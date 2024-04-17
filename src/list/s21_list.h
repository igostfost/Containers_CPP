/**
 * @file s21_list.h
 * @brief Двусвязный список (list).
 *
 * Класс list обеспечивает удобство управления данными в двусвязном списке.
 * Он предоставляет методы для вставки, удаления и доступа к элементам списка
 * с возможностью перемещения в обе стороны с использованием итераторов.
 * Данная реализация list гарантирует постоянное время вставки и удаления
 * элементов на любой позиции, при условии наличия итератора, указывающего на
 * эту позицию.
 */

#ifndef S21_LIST_H_
#define S21_LIST_H_

#include <iostream>

namespace s21 {
template <typename T>
class list {
 public:
  class ListIterator;
  class ListConstIterator;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;
  using iterator = list<T>::ListIterator;
  using const_iterator = list<T>::ListConstIterator;

  typedef struct Node_ {
    T data;
    Node_ *prev;
    Node_ *next;
    explicit Node_(const T &data) : data(data), prev(nullptr), next(nullptr) {}
  } Node_;

  class ListIterator {
   public:
    ListIterator() : iter_(nullptr) {}

    ListIterator(const ListIterator &other) : iter_(other.iter_) {}

    explicit ListIterator(Node_ *iter) : iter_(iter) {}

    ListIterator &operator=(const ListIterator &other) {
      iter_ = other.iter_;
      return *this;
    }
    bool operator==(const ListIterator &other) const {
      return iter_ == other.iter_;
    }
    bool operator!=(const ListIterator &other) const {
      return iter_ != other.iter_;
    }

    ListIterator operator++() {
      iter_ = iter_->next;
      return *this;
    }
    ListIterator operator--() {
      iter_ = iter_->prev;
      return *this;
    }

    ListIterator operator++(int) {
      ListIterator tmp(*this);
      iter_ = iter_->next;
      return tmp;
    }

    reference operator*() { return iter_->data; }

    T *operator->() { return &(iter_->value); }

    Node_ *get_node() { return iter_; };

   private:
    Node_ *iter_ = nullptr;
  };

  class ListConstIterator {
   public:
    ListConstIterator() : iter_(nullptr) {}

    ListConstIterator(const ListConstIterator &other) : iter_(other.iter_) {}

    explicit ListConstIterator(Node_ *iter_) : iter_(iter_) {}

    ListConstIterator &operator=(const ListConstIterator &other) {
      iter_ = other.iter_;
      return *this;
    }

    bool operator==(const ListConstIterator &other) const {
      return iter_ == other.iter_;
    }

    bool operator!=(const ListConstIterator &other) const {
      return iter_ != other.iter_;
    }

    ListConstIterator operator++() {
      iter_ = iter_->next;
      return *this;
    }

    ListConstIterator operator--() {
      iter_ = iter_->prev;
      return *this;
    }

    ListConstIterator operator++(int) {
      ListConstIterator tmp(*this);
      iter_ = iter_->next;
      return tmp;
    }

    const_reference operator*() const { return iter_->data; }

    const Node_ *get_node() const { return iter_; }

   private:
    const Node_ *iter_ = nullptr;
  };

  // ---------- start constructors ---------

  list() noexcept : head_(nullptr), tail_(nullptr), size_(0){};

  explicit list(size_type n) : head_(nullptr), tail_(nullptr), size_(0) {
    for (size_type i = 0; i < n; i++) {
      push_back(value_type());
    }
  };

  list(std::initializer_list<value_type> const &items)
      : head_(nullptr), tail_(nullptr), size_(0) {
    for (auto const &items : items) {
      push_back(items);
    }
  };

  list(const list &l)
      : head_(nullptr), tail_(nullptr), size_(0) {  // copy constructor
    Node_ *current = l.head_;
    while (current != nullptr) {
      push_back(current->data);
      current = current->next;
    }
  };

  list(list &&l)
      : head_(l.head_), tail_(l.tail_), size_(l.size_) {  // move constructor
    l.head_ = nullptr;
    l.tail_ = nullptr;
    l.size_ = 0;
  };

  list &operator=(list &&l) {
    if (this == &l) {
      return *this;
    }
    Node_ *current = this->head_;
    while (head_ != nullptr) {
      current = head_->next;
      delete current;
    }
    head_ = l.head_;
    tail_ = l.tail_;
    size_ = l.size_;

    l.head_ = nullptr;
    l.tail_ = nullptr;
    l.size_ = 0;

    return *this;
  };

  ~list() {
    while (head_ != nullptr) pop_front();
  }

  // ---------- end constructors ---------

  const_reference front() const {
    if (head_ == nullptr) {
      throw std::out_of_range("Empty list");
    }
    return head_->data;
  };

  const_reference back() const {
    if (head_ == nullptr) {
      throw std::out_of_range("Empty list");
    }
    return tail_->data;
  };

  iterator begin() { return iterator(head_); };

  iterator end() { return iterator(tail_); };

  const_iterator c_begin() { return const_iterator(head_); };
  const_iterator c_end() { return const_iterator(tail_); };

  bool empty() { return size_ == 0; };

  size_type size() { return size_; };

  size_type max_size() const noexcept {
    return std::numeric_limits<size_type>::max();
  }

  void push_back(const_reference value) {
    Node_ *new_node = new Node_(value);
    if (head_ == nullptr) {
      head_ = tail_ = new_node;
    } else {
      tail_->next = new_node;
      new_node->prev = tail_;
      tail_ = new_node;
    }
    size_++;
  };

  void push_front(const_reference value) {
    Node_ *new_node = new Node_(value);
    if (head_ == nullptr) {
      head_ = tail_ = new_node;
    } else {
      head_->prev = new_node;
      new_node->next = head_;
      head_ = new_node;
    }
    size_++;
  };

  void pop_front() {
    if (head_ == nullptr) return;

    Node_ *tmp_node = head_->next;
    if (tmp_node != nullptr) {
      tmp_node->prev = nullptr;
    } else {
      tail_ = nullptr;
    }
    delete head_;
    head_ = tmp_node;
    size_--;
  }

  void pop_back() {
    if (head_ == nullptr) return;

    Node_ *tmp_node = tail_->prev;
    if (tmp_node != nullptr) {
      tmp_node->next = nullptr;
    } else {
      head_ = tmp_node;
    }
    delete tail_;
    tail_ = tmp_node;
    size_--;
  };

  void clear() {
    while (head_ != nullptr && tail_ != nullptr) {
      pop_front();
    }
  };

  iterator insert(iterator pos, const_reference value) {
    Node_ *newNode = new Node_(value);
    if (pos.get_node() == tail_) {
      if (empty()) {
        head_ = newNode;
        tail_ = newNode;
        size_++;
      } else {
        Node_ *tmp = tail_;
        tail_->next = newNode;
        newNode->prev = tmp;
        tail_ = newNode;
        size_++;
      }
    } else {
      Node_ *prevNode = pos.get_node()->prev;
      if (prevNode) {
        prevNode->next = newNode;
        newNode->prev = prevNode;
      }
      newNode->next = pos.get_node();
      pos.get_node()->prev = newNode;
      if (pos.get_node() == head_) {
        head_ = newNode;
      }
      size_++;
    }
    return iterator(newNode);
  }

  void erase(iterator pos) {
    Node_ *current = pos.get_node();

    if (current == nullptr) {
      throw std::out_of_range(
          "Элемента не существует, попытка удаления неудачна");
    }

    if (current->prev) {
      current->prev->next = current->next;
    }
    if (current->next) {
      current->next->prev = current->prev;
    }

    if (current == head_) {
      head_ = current->next;
    }
    if (current == tail_) {
      tail_ = current->prev;
    }

    if (head_ == nullptr) {
      tail_ = nullptr;
    }

    delete current;
    size_--;
  }

  void swap(list &other) noexcept {
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
    std::swap(size_, other.size_);
  }

  void merge(list &other) {
    list result;
    iterator this_begin = begin();
    iterator other_begin = other.begin();
    if (other.empty()) {
      return;
    }
    if (empty()) {
      other.sort();
      *this = std::move(other);
      return;
    }
    while (this_begin != ++end()) {
      result.push_back(*this_begin);
      this_begin++;
    }
    while (other_begin != ++other.end()) {
      result.push_back(*other_begin);
      other_begin++;
    }
    result.sort();
    clear();
    *this = std::move(result);
  }

  void splice(const_iterator pos, list &other) {
    // находим наши узлы
    Node_ *target_node = const_cast<s21::list<int>::Node_ *>(pos.get_node());
    Node_ *first_node_other = other.head_;
    Node_ *last_node_other = other.tail_;
    if (other.head_ == nullptr)
      return;  // если список пуст, то ничего не делаем
    if (target_node != nullptr) {  // Обновляем указатели в начальном списке
      Node_ *prev_target_node = target_node->prev;
      if (prev_target_node != nullptr) {
        prev_target_node->next = first_node_other;
      }

      first_node_other->prev = prev_target_node;
      last_node_other->next = target_node;
      target_node->prev = last_node_other;
      if (target_node ==
          head_) {  // если pos указывает на началоб то нужно обновить head_
        head_ = first_node_other;
      }
    } else {  // если pos указывает на конец начального списка
      if (tail_ != nullptr) {  // если начальный список не пустой
        tail_->next = first_node_other;
        first_node_other->prev = tail_;
      } else {  // если все-таки пустой
        head_ = first_node_other;
      }
      tail_ = last_node_other;
    }
    size_ += other.size_;
    other.size_ = 0;
    other.head_ = nullptr;
    other.tail_ = nullptr;
  }

  void reverse() noexcept {
    if (head_ == nullptr ||
        head_ == tail_) {  // Пустой список или один элемент - ничего не делаем
      return;
    }
    Node_ *current = head_;
    while (current != nullptr) {
      std::swap(current->prev, current->next);
      current = current->prev;
    }
    std::swap(head_, tail_);
  }

  void unique() {
    auto iter = begin();
    Node_ *current_node;
    Node_ *next_node;
    if (empty()) return;
    for (; iter != end();) {
      current_node = iter.get_node();
      next_node = current_node->next;
      if (next_node && current_node->data == next_node->data) {
        erase(iter);
        iter = iterator(next_node);
      } else {
        ++iter;
      }
    }
  }

  void sort() {
    for (auto iter = begin(); iter != ++end(); ++iter) {
      for (auto innerIter = begin(); innerIter != ++end(); ++innerIter) {
        auto nextIter = innerIter;
        ++nextIter;

        if (nextIter != ++end()) {
          if (*innerIter > *nextIter) {
            std::swap(*innerIter, *nextIter);
          }
        }
      }
    }
  }

  // вспомогательные методы
  void print_l() {
    for (Node_ *ptr = head_; ptr != nullptr; ptr = ptr->next) {
      std::cout << ptr->data << " ";
    }
  };

  //-------------- END PUBLIC --------------------
 private:
  Node_ *head_;
  Node_ *tail_;
  size_t size_;
};
}  // namespace s21

#endif  //_S21_LIST_H_