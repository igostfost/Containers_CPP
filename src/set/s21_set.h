#ifndef S21_SET_H
#define S21_SET_H

#include "rb_tree.h"

namespace s21 {

template <class Key>
class Set : public RBTree<Key, Key> {
 public:
  using value_type = Key;
  using key_type = Key;
  using reference = Key &;
  using const_reference = const Key &;
  using iterator = typename RBTree<Key, Key>::iterator;
  using const_iterator = typename RBTree<Key, Key>::const_iterator;
  using size_type = size_t;
  using set = Set;

 public:
  Set() : RBTree<Key, Key>() {}
  Set(std::initializer_list<value_type> const &items)
      : RBTree<Key, Key>(items) {}
  Set(const Set &other) : RBTree<Key, Key>(other) {}
  Set(Set &&set) : RBTree<Key, Key>(std::move(set)) {}
  // Оператор перемещающего присвоения
  Set &operator=(Set &&set) {
    if (this != &set) {
      // Вызываем оператор перемещающего присвоения базового класса
      RBTree<Key, Key>::operator=(std::move(set));
    }
    return *this;
  }
  ~Set() = default;

  void insert(const key_type &key) {
    // Вызываем метод вставки дерева, передавая ключ как и данные
    RBTree<Key, Key>::insert(key, key);
  }
};

}  // namespace s21

#endif  // RB_TREE_H
