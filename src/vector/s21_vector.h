#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include <limits>

namespace s21 {

template <typename T, bool IsConst>
class CommonIterator;

template <typename T, typename Alloc = std::allocator<T>>
class Vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using pointer = T *;
  using const_pointer = const T *;
  using iterator = CommonIterator<T, false>;
  using const_iterator = CommonIterator<T, true>;
  using size_type = size_t;

  Vector() noexcept : alloc(), array_(nullptr), size_(0), capacity_(0){};

  explicit Vector(size_t count)
      : alloc(), array_(nullptr), size_(count), capacity_(count) {
    AllocateMemory();
    for (size_type i = 0; i < size_; ++i) {
      ConstructDestroy(i, value_type());
    }
  }

  Vector(std::initializer_list<value_type> const &items)
      : alloc(), array_(nullptr), size_(items.size()), capacity_(items.size()) {
    AllocateMemory();
    iterator it = begin();
    for (auto i = items.begin(); i < items.end(); ++i) {
      std::allocator_traits<Alloc>::construct(alloc, std::addressof(*it), *i);
      ++it;
    }
  };

  Vector(const Vector &v)
      : alloc(), array_(nullptr), size_(v.size_), capacity_(v.capacity_) {
    AllocateMemory();
    iterator it = begin();
    for (auto i = v.cbegin(); i < v.cend(); ++i) {
      std::allocator_traits<Alloc>::construct(alloc, std::addressof(*it), *i);
      ++it;
    }
  };

  Vector(Vector &&v) noexcept
      : array_(v.array_), size_(v.size_), capacity_(v.capacity_) {
    v.array_ = nullptr;
    v.size_ = 0;
    v.capacity_ = 0;
  };

  Vector &operator=(Vector &&v) noexcept {
    if (this != &v) {
      clear();
      Vector new_vector(std::move(v));
      swap(new_vector);
    }
    return *this;
  };

  Vector &operator=(const Vector &v) {
    if (this != &v) {
      if (v.capacity() < capacity_) {
        for (size_type i = 0; i < size_; ++i) {
          std::allocator_traits<Alloc>::destroy(alloc, array_ + i);
        }
        for (size_type i = 0; i < v.size(); ++i) {
          ConstructDestroy(i, v.at(i));
        }
        size_ = v.size();
      } else {
        clear();
        Vector new_vector(v);
        swap(new_vector);
      }
    }
    return *this;
  };

  ~Vector() {
    DeleteMemory();
    size_ = 0;
    capacity_ = 0;
    array_ = nullptr;
  };

  reference at(size_type pos) const {
    if (pos >= size_) {
      throw std::out_of_range("error");
    } else {
      return array_[pos];
    }
  };

  reference operator[](size_type pos) {
    if (pos > size_) {
      throw std::out_of_range("error");
    }
    return array_[pos];
  };

  const_reference front() const { return *(array_); };

  const_reference back() const { return *(array_ + size_ - 1); };

  pointer data() noexcept {
    if (array_ == nullptr) {
      return nullptr;
    } else
      return array_;
  };

  iterator begin() noexcept { return iterator(array_); };

  iterator end() noexcept { return iterator(array_ + size_); };

  const_iterator cbegin() const noexcept { return const_iterator(array_); };

  const_iterator cend() const noexcept {
    return const_iterator(array_ + size_);
  };

  bool empty() const noexcept {
    bool result = false;
    if (array_ == nullptr) {
      result = true;
    }
    return result;
  };

  size_type size() const noexcept { return size_; };

  size_type max_size() const noexcept {
    return std::allocator_traits<Alloc>::max_size(alloc);
  };

  void reserve(size_type new_cap) {
    if (new_cap <= capacity_) {
      return;
    }
    ThrowFunction(size_, new_cap);
    capacity_ = new_cap;
  }

  size_type capacity() const noexcept { return capacity_; };

  void shrink_to_fit() {
    if (capacity_ == size_) {
      return;
    }
    ThrowFunction(size_, capacity_);
    capacity_ = size_;
  };

  void clear() noexcept {
    for (size_type i = 0; i < size_; ++i) {
      std::allocator_traits<Alloc>::destroy(alloc, array_ + i);
    }
    size_ = 0;
  };

  iterator insert(iterator pos, const_reference value) {
    if (pos >= end()) {
      return pos;
    }
    if (size_ == capacity_) {
      pos = InsertReverse(pos, value);
      return pos;
    }
    size_++;
    ConstructDestroy(size_, value_type());
    auto iter = this->end();
    iter--;
    for (; iter > pos; iter--) {
      iter--;
      auto it = std::move_if_noexcept(*iter);
      iter++;
      *iter = std::move_if_noexcept(it);
    }
    *pos = value;
    return pos;
  };

  iterator erase(iterator pos) {
    if (pos >= this->end() || pos < this->begin()) {
      return pos;
    }
    auto it = end();
    it--;
    for (auto iter = pos; iter < it; iter++) {
      iter++;
      auto it = std::move_if_noexcept(*iter);
      iter--;
      *iter = std::move_if_noexcept(it);
    }
    size_--;
    return pos;
  };

  void push_back(const_reference value) {
    if (capacity_ == 0) {
      size_++;
      capacity_++;
      AllocateMemory();
      ConstructDestroy(0, value);
      return;
    }
    if (size_ == capacity_) {
      reserve(capacity_ * 2);
    }
    ConstructDestroy(size_, value);
    size_++;
  };

  void pop_back() {
    if (size_ < 1) {
      return;
    } else if (size_ == 1) {
      std::allocator_traits<Alloc>::destroy(alloc, array_);
    } else {
      std::allocator_traits<Alloc>::destroy(alloc, array_ + size_);
      size_ = size_ - 1;
    }
  };

  void swap(Vector &other) noexcept {
    std::swap(alloc, other.alloc);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
    std::swap(array_, other.array_);
  };

  void resize(size_type n) {
    if (n == size_) {
      return;
    }
    if (n > capacity_) {
      reserve(n);
      size_ = n;
    }
    if (n < capacity_) {
      size_ = n;
    }
  };

 private:
  Alloc alloc;
  pointer array_;
  size_type size_;
  size_type capacity_;

  void AllocateMemory() {
    array_ = std::allocator_traits<Alloc>::allocate(alloc, capacity_);
  }

  void DeleteMemory() {
    for (size_type i = 0; i < size_; ++i) {
      std::allocator_traits<Alloc>::destroy(alloc, array_ + i);
    }
    std::allocator_traits<Alloc>::deallocate(alloc, array_, capacity_);
    array_ = nullptr;
  }

  void ThrowFunction(size_type size, size_type cap) {
    pointer new_array = std::allocator_traits<Alloc>::allocate(alloc, cap);
    size_type i = 0;
    try {
      if (size_ == 0) {
        std::allocator_traits<Alloc>::construct(
            alloc, std::addressof(*(new_array + i)), T());
      }
      for (; i < size; ++i) {
        std::allocator_traits<Alloc>::construct(
            alloc, std::addressof(*(new_array + i)),
            std::move_if_noexcept(array_[i]));
      }
    } catch (...) {
      for (; i < size; ++i) {
        std::allocator_traits<Alloc>::destroy(alloc, new_array + i);
      }
      std::allocator_traits<Alloc>::deallocate(alloc, new_array, cap);
      throw;
    }
    for (size_type i = 0; i < size; ++i) {
      std::allocator_traits<Alloc>::destroy(alloc, array_ + i);
    }
    std::allocator_traits<Alloc>::deallocate(alloc, array_, cap);
    array_ = new_array;
  }

  iterator InsertReverse(iterator pos, const_reference value) {
    auto iter = begin();
    size_type index = 0;
    for (size_type i = 0; i < size_; i++) {
      if (iter == pos) {
        index = i;
      }
      iter++;
    }
    reserve(capacity_ * 2);
    size_++;
    ConstructDestroy(size_, value_type());
    size_type i = size_;
    for (; i != index; i--) {
      i--;
      auto it = std::move_if_noexcept(array_[i]);
      i++;
      array_[i] = std::move_if_noexcept(it);
    }
    size_t j = 0;
    for (auto iter = begin(); iter < end(); ++iter) {
      if (j == i) {
        pos = iter;
      }
      j++;
    }
    array_[i] = value;
    return pos;
  }

  void ConstructDestroy(size_type shift, const_reference value) {
    try {
      std::allocator_traits<Alloc>::construct(alloc,
                                              std::addressof(*(array_ + shift)),
                                              std::move_if_noexcept(value));
    } catch (...) {
      std::allocator_traits<Alloc>::destroy(alloc, array_ + shift);
      throw;
    }
  }
};

template <typename T, bool IsConst>
class CommonIterator {
 public:
  friend class Vector<T>;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using pointer = T *;
  using const_pointer = const T *;
  using size_type = size_t;
  using conditional_ptr = std::conditional_t<IsConst, const_pointer, pointer>;
  using conditional_ref =
      std::conditional_t<IsConst, const_reference, reference>;

  CommonIterator() noexcept : value(nullptr){};
  CommonIterator(pointer current) : value(current) {}

  conditional_ref operator+(int n) { return *(value + n); }
  conditional_ref operator-(int n) { return *(value - n); }
  conditional_ref operator++(int) { return *(value++); }
  conditional_ref operator--(int) { return *(value--); }
  conditional_ref operator++() { return *(value++); }
  conditional_ref operator--() { return *(value--); }
  bool operator<=(const CommonIterator &other) const {
    return (value <= other.value);
  }
  bool operator>=(const CommonIterator &other) const {
    return (value >= other.value);
  }
  bool operator<(const CommonIterator &other) const {
    return (value < other.value);
  }
  bool operator>(const CommonIterator &other) const {
    return (value > other.value);
  }
  bool operator!=(const CommonIterator &other) const {
    return (value != other.value);
  }
  bool operator==(const CommonIterator &other) const {
    return (value == other.value);
  }
  conditional_ref operator*() const { return *value; }
  conditional_ptr operator->() const { return value; }

 private:
  conditional_ptr value;
};

};      // namespace s21
#endif  //_VECTOR_H_
