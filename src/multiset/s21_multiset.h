#ifndef S21_MULTISET_H
#define S21_MULTISET_H

#include "multi_rb_tree.h"

namespace s21 {

template <class Key>
class Multiset : public MRBTree<Key, Key> {
 public:
  using value_type = Key;
  using key_type = Key;
  using reference = Key &;
  using const_reference = const Key &;
  using iterator = typename MRBTree<Key, Key>::iterator;
  using const_iterator = typename MRBTree<Key, Key>::const_iterator;
  using size_type = size_t;
  using multiset = Multiset;

 public:
  Multiset() : MRBTree<Key, Key>() {}
  Multiset(std::initializer_list<value_type> const &items)
      : MRBTree<Key, Key>(items) {}
  Multiset(const Multiset &other) : MRBTree<Key, Key>(other) {}
  Multiset(Multiset &&multiset) : MRBTree<Key, Key>(std::move(multiset)) {}
  // Оператор перемещающего присвоения
  Multiset &operator=(Multiset &&multiset) {
    if (this != &multiset) {
      // Вызываем оператор перемещающего присвоения базового класса
      MRBTree<Key, Key>::operator=(std::move(multiset));
    }
    return *this;
  }
  ~Multiset() = default;

  void insert(const key_type &key) {
    // Вызываем метод вставки дерева, передавая ключ как и данные
    MRBTree<Key, Key>::insert(key, key);
  }
};

}  // namespace s21

#endif  // S21_MULTISET_H
