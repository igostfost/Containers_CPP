#ifndef S21_ARRAY_H_
#define S21_ARRAY_H_

#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename T, size_t N>
class Array {
 public:
  // Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  // Member functions
  Array() = default;  // Default constructor

  Array(std::initializer_list<value_type> const &items) {
    std::copy(items.begin(), items.end(), data_);
  }  // Initializer list constructor

  Array(const Array &a) : N_(a.N_) {
    if (N_ == a.N_) {
      for (size_t i = 0; i < N_; ++i) {
        data_[i] = a.data_[i];
      }
    }
  }  // Copy constructor

  Array(Array &&a) noexcept {
    if (N_ == a.N_) {
      for (size_t i = 0; i < N_; ++i) {
        data_[i] = std::move_if_noexcept(a.data_[i]);
      }
      N_ = a.N_;
      a.N_ = 0;
    }

  }  // Move constructor

  Array &operator=(Array &&a) noexcept {
    if (this != &a) {
      Array new_array(std::move(a));
      std::swap(data_, new_array.data_);
      std::swap(N_, new_array.data_);
    }
    return *this;
  }  // Move assignment operator

  Array &operator=(const Array &a) noexcept {
    if (this != &a) {
      Array new_array(a);
      std::swap(data_, new_array.data_);
      std::swap(N_, new_array.data_);
    }
    return *this;
  }

  ~Array() = default;  // Destructor

  // Element access
  reference at(size_type pos) {
    if (pos >= N_) {
      throw std::out_of_range("Index out of range");
    }
    return data_[pos];
  }

  reference operator[](size_type pos) { return data_[pos]; }

  const_reference front() const { return data_[0]; }

  const_reference back() const { return data_[N_ - 1]; }

  iterator data() { return data_; }

  // Iterators
  iterator begin() { return data_; }

  iterator end() { return data_ + N_; }

  // Capacity
  bool empty() const { return N_ == 0; }

  size_type size() const { return N_; }

  size_type max_size() const { return N_; }

  // Modifiers
  void swap(Array &other) {
    if (N_ == other.N_ && !empty()) {
      std::swap_ranges(begin(), end(), other.begin());
    }
  }

  void fill(const_reference value) {
    if (!empty()) {
      std::fill(begin(), end(), value);
    }
  }

 private:
  value_type data_[N];
  size_type N_ = N;
};
}  // namespace s21

#endif
