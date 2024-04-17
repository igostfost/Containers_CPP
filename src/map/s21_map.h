#ifndef _MAP_H_
#define _MAP_H_

#include <iostream>

#include "tree.h"

namespace s21 {

template <typename Key, typename T, bool IsConst>
class MapCommonIterator;

template <typename Key, typename T, typename Compare = std::less<Key>,
          typename Alloc = std::allocator<T>>
class Map : public Tree<Key, T> {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const Key, T>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using pointer = value_type*;
  using const_pointer = const value_type*;
  using NodeAlloc = typename std::allocator_traits<
      Alloc>::template rebind_alloc<Node<key_type, mapped_type>>;
  using DataAlloc = typename std::allocator_traits<
      Alloc>::template rebind_alloc<std::pair<const Key, T>>;
  using iterator = TreeCommonIterator<key_type, mapped_type, false>;
  using const_iterator = TreeCommonIterator<key_type, mapped_type, true>;
  using size_type = size_t;

  friend class Tree<Key, T>;

  Map() : tree_(){};

  Map(std::initializer_list<value_type> const& items) {
    for (auto i = items.begin(); i != items.end(); ++i) {
      tree_.insert(*i);
    }
  };

  Map(const Map& m) : Tree<key_type, mapped_type, Compare, Alloc>(m.tree_) {
    tree_.CopyElementsForTree(m.tree_);
  };

  Map(Map&& m) { tree_.MoveTree(std::move(m.tree_)); }

  Map& operator=(Map&& m) {
    if (this != &m) {
      clear();
      Map new_map(std::move(m.tree_));
      swap(new_map);
    }
    return *this;
  };

  Map& operator=(const Map& m) {
    if (this != &m) {
      clear();
      Map new_map(m.tree_);
      swap(new_map);
    }
    return *this;
  };

  ~Map(){};

  T& at(const Key& key) const {
    try {
      return tree_.at(key);
    } catch (...) {
      throw std::out_of_range("error");
    }
  };

  T& operator[](const key_type& key) { return tree_[key]; };

  iterator begin() noexcept { return tree_.begin(); };

  iterator end() noexcept { return tree_.end(); }

  const_iterator cbegin() const noexcept { return tree_.cbegin(); };
  const_iterator cend() const noexcept {
    return tree_.cend();
    ;
  };

  bool empty() const noexcept { return tree_.empty(); };

  size_type size() const noexcept { return tree_.size(); };

  size_type max_size() const noexcept { return tree_.max_size(); };

  void clear() { tree_.clear(); };

  std::pair<iterator, bool> insert(const value_type& value) {
    auto iter = tree_.insert(value);
    return iter;
  };

  std::pair<iterator, bool> insert(const key_type& key,
                                   const mapped_type& obj) {
    auto iter = tree_.insert(key, obj);
    return iter;
  };

  std::pair<iterator, bool> insert_or_assign(const key_type& key,
                                             const mapped_type& obj) {
    auto iter = tree_.insert_or_assign(key, obj);
    return iter;
  };

  void erase(iterator pos) { tree_.erase(pos); };
  void swap(Map& other) { tree_.swap(other.tree_); };
  void merge(Map& other) { tree_.merge(other.tree_); };
  bool contains(const Key& key) const { return tree_.contains(key); };

 private:
  Tree<key_type, mapped_type, Compare, Alloc> tree_;
};

};      // namespace s21
#endif  //_MAP_H_
