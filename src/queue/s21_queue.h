#ifndef s21_queue_h
#define s21_queue_h

#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename T>
class Queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  // default constructor, creates empty queue
  Queue() : data_(nullptr), size_(0) {}

  // initializer list constructor, creates queue initizialized using
  Queue(std::initializer_list<value_type> const &items) : Queue() {
    if (items.size() != 0) {
      size_ = items.size();
      data_ = new value_type[size_];
      std::move(items.begin(), items.end(), data_);
    }
  }

  // copy constructor
  Queue(const Queue &q) {
    if (&q != this) {
      size_ = q.size_;
      data_ = new value_type[size_];
      std::copy(q.data_, q.data_ + size_, data_);
    }
  }

  // move constructor
  Queue(Queue &&q) noexcept {
    size_ = q.size_;
    data_ = q.data_;
    q.size_ = 0;
    q.data_ = nullptr;
  }

  // operator overload for moving object
  Queue &operator=(Queue &&q) {
    if (this != &q) {
      delete[] data_;

      size_ = q.size_;
      data_ = q.data_;

      q.size_ = 0;
      q.data_ = nullptr;
    }
    return *this;
  }

  // destructor
  ~Queue() {
    size_ = 0;
    delete[] data_;
  }

  // access the first element
  const_reference front() const {
    if (empty()) {
      throw std::out_of_range("Queue is empty");
    }
    return data_[0];
  }

  // access the last element
  const_reference back() const {
    if (empty()) {
      throw std::out_of_range("Queue is empty");
    }
    return data_[size_ - 1];
  }

  // checks whether the container is empty
  bool empty() const { return size_ == 0; }

  // returns the number of elements in container
  size_type size() const { return size_; }

  // inserts element at the end
  void push(const_reference value) {
    try {
      value_type *newData = new value_type[size_ + 1];
      std::copy(data_, data_ + size_, newData);
      newData[size_] = std::move(value);
      delete[] data_;
      data_ = newData;
      size_ += 1;
    } catch (const std::bad_alloc &e) {
      std::cerr << "Exception caught: " << e.what() << std::endl;
    }
  }

  // removes the first element
  void pop() {
    if (empty()) {
      throw std::out_of_range("Queue is empty");
    }
    value_type *newData = new value_type[size_ - 1];
    std::copy(data_ + 1, data_ + size_, newData);
    delete[] data_;
    data_ = newData;
    size_ -= 1;
  }

  // 	swaps the contents
  void swap(Queue &q) {
    value_type *tempData = data_;
    data_ = q.data_;
    q.data_ = tempData;

    size_type tempSize = size_;
    size_ = q.size_;
    q.size_ = tempSize;
  }

 private:
  value_type *data_;
  size_type size_;
};
}  // namespace s21

#endif  //_S21_QUEUE_H_
