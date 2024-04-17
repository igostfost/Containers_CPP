#ifndef RB_TREE_H
#define RB_TREE_H

#include <iostream>
#include <queue>    // для вывода - не обзязательно
#include <utility>  // для использования std::pair

namespace s21 {
template <typename Key, typename Data>
class MRBTree {
 public:
  class TreeIterator;  // итераторы
  class ConstTreeIterator;
  struct TreeNode;                  // узел
  enum class Color { RED, BLACK };  // класс для цвета узлов

  // псевдонимы
  using key_type = Key;
  using data_type = Data;
  using value_type = data_type;
  using const_reference = const data_type &;
  using iterator = TreeIterator;
  using const_iterator = ConstTreeIterator;
  using size_type = size_t;
  using pointer = data_type *;
  using reference = data_type &;
  using iterator_category = std::bidirectional_iterator_tag;

  // Конструктор по умолчанию
  MRBTree() : root_(nullptr), size_(0) {}

  /*Конструктор с параметрами
  Позваляет инициализировать в виде:
  MRBTree<int, std::string> myTree{
      {1, "one"},
      {2, "two"},
      {3, "three"}
  };*/
  MRBTree(
      std::initializer_list<std::pair<const key_type, const data_type>> values)
      : root_(nullptr), size_(0) {
    for (const auto &pair : values) {
      insert(pair.first, pair.second);
    }
  }

  MRBTree(std::initializer_list<data_type> const &items)
      : root_(nullptr), size_(0) {
    for (const auto &item : items) {
      insert(item, item);
    }
  }
  // конструктор перемещения
  MRBTree(MRBTree &&other) noexcept : root_(other.root_), size_(other.size_) {
    other.root_ = nullptr;
    other.size_ = 0;
  }

  // конструктор копирования
  MRBTree(const MRBTree &other) : root_(nullptr), size_(0) {
    // Рекурсивно копируем узлы из другого дерева
    root_ = copyTree(other.root_, nullptr);
    size_ = other.size_;
  }

  // деструктор
  ~MRBTree() {
    clear();
    root_ = nullptr;
  }

  // Метод вставки
  iterator insert(const key_type &key, const data_type &data) {
    // Создаем новый узел с переданными значениями
    TreeNode *newNode = new TreeNode(key, data, Color::RED);
    // Выполняем обычную вставку как в двоичном дереве поиска
    insertNode(newNode);
    // Выполняем балансировку после вставки
    fixInsertion(newNode);
    // Возвращаем итератор на вставленный элемент
    return iterator(newNode);
  }

  // Метод equal_range
  std::pair<iterator, iterator> equal_range(const Key &key) {
    iterator lower = lower_bound(key);
    iterator upper = upper_bound(key);

    // Если ключ не найден, вернем диапазон, где оба итератора указывают на
    // конец
    if (lower == end() || upper == end()) {
      return std::make_pair(end(), end());
    }

    // Если найден, вернем диапазон между lower и upper
    return std::make_pair(lower, upper);
  }

  // Метод lower_bound
  iterator lower_bound(const Key &key) {
    TreeNode *current = root_;
    TreeNode *result = nullptr;

    while (current != nullptr) {
      if (current->key_ < key) {
        current = current->right_;
      } else {
        result = current;
        current = current->left_;
      }
    }

    return iterator(result);
  }

  // Метод upper_bound
  iterator upper_bound(const Key &key) {
    TreeNode *current = root_;
    TreeNode *result = nullptr;

    while (current != nullptr) {
      if (key < current->key_) {
        result = current;
        current = current->left_;
      } else {
        current = current->right_;
      }
    }

    return iterator(result);
  }

  void erase(const key_type &key) {
    // Находим узел для удаления
    while (TreeNode *nodeToRemove = findNode(key)) {
      if (nodeToRemove != nullptr) {
        // Вызываем функцию удаления с найденным узлом
        removeNode(nodeToRemove);
      } else {
        throw std::logic_error(
            "Node with the specified key does not exist in the tree");
      }
    }
  }

  // Метод для вывода корня дерева
  TreeNode *get_root() const { return root_; }

  // Метод поиска по ключу
  TreeNode *find(const key_type &key) const { return findNode(key); }

  // Метод для получения размера
  size_type size() const { return size_; }

  // Метод для проверки на пустоту
  bool empty() const { return size_ == 0; }

  // Метод для получения максимального размера
  size_type max_size() const { return std::numeric_limits<size_type>::max(); }

  // Метод для проверки наличия ключа в дереве
  bool contains(const key_type &key) const { return findNode(key) != nullptr; }

  // Метод для очистки дерева
  void clear() {
    clearRecursive(root_);  // Рекурсивное удаление всех узлов дерева
    root_ = nullptr;
    size_ = 0;
  }

  iterator begin() {
    TreeNode *leftmost = findLeftmost(root_);
    return iterator(leftmost);
  }

  iterator end() { return iterator(nullptr); }

  // Метод обмена содержимым двух деревьев
  void swap(MRBTree &other) noexcept {
    std::swap(root_, other.root_);
    std::swap(size_, other.size_);
  }

  // Метод объединения содержимого двух деревьев написан под множество
  void merge(MRBTree &other) {
    // Добавляем все элементы из другого множества
    for (auto &element : other) {
      insert(element, element);
    }
    // Очищаем содержимое другого множества
    other.clear();
  }

  // Оператор перемещающего присвоения
  MRBTree &operator=(MRBTree &&other) noexcept {
    if (this != &other) {
      // Очищаем текущее дерево перед перемещением данных
      clear();

      // Перемещаем корень и размер из другого объекта
      root_ = other.root_;
      size_ = other.size_;

      // Обнуляем указатели в другом объекте, чтобы избежать освобождения памяти
      // при его разрушении
      other.root_ = nullptr;
      other.size_ = 0;
    }
    return *this;
  }

  // Метод подсчета количества элементов с определенным ключом
  size_type count(const Key &key) const { return countRecursive(root_, key); }

  // Метод для вывода значений дерева по уровням - необязательный метод
  void print_tree_level(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    std::queue<std::pair<TreeNode *, int>> levelQueue;
    levelQueue.push({root, 0});

    int currentLevel = 0;

    while (!levelQueue.empty()) {
      auto [current, level] = levelQueue.front();
      levelQueue.pop();

      if (level > currentLevel) {
        // Переход на новую строку между уровнями
        std::cout << "level: " << currentLevel << std::endl;
        currentLevel = level;
      }

      std::string color = (current->color_ == Color::RED) ? "RED" : "BLACK";
      std::cout << current->key_ << " : " << current->data_ << " " << color
                << " | ";

      if (current->left_) {
        levelQueue.push({current->left_, level + 1});
      }
      if (current->right_) {
        levelQueue.push({current->right_, level + 1});
      }
    }

    // Вывод номера уровня для последней строки
    std::cout << " level: " << currentLevel << std::endl;
  }

  void print_tree(TreeNode *node) {
    if (node == nullptr) {
      return;
    }
    if (node) {
      print_tree(node->left_);
      std::string color = (node->color_ == Color::RED) ? "RED" : "BLACK";
      std::cout << "key: " << node->key_ << " : " << node->data_
                << " color: " << color << std::endl;
      print_tree(node->right_);
    }
  }

  //////////////////////////////// узел дерева ////////////////////////////////
  typedef struct TreeNode {
    key_type key_;                // ключ
    data_type data_;              // значение
    TreeNode *parent_ = nullptr;  // указатель на родителя
    TreeNode *left_ = nullptr;  // левый ребенок указатель
    TreeNode *right_ = nullptr;  // правый ребенок указатель
    Color color_ = Color::RED;  // цвет узла

    // конструктор с всеми параметрами
    TreeNode(key_type key, data_type data, Color color)
        : key_(key),
          data_(data),
          parent_(nullptr),
          left_(nullptr),
          right_(nullptr),
          color_(color) {}

    // конструктор без цвета, используется красный цвет по умолчанию
    TreeNode(key_type key, data_type data)
        : key_(key),
          data_(data),
          parent_(nullptr),
          left_(nullptr),
          right_(nullptr),
          color_(Color::RED) {}

    friend std::ostream &operator<<(std::ostream &os, const TreeNode &node) {
      os << node.key_;  // Пример вывода ключа
      return os;
    }

  } TreeNode;

  //////////////////////////// итератор константный////////////////////////////
  class ConstTreeIterator {
   public:
    // переназначаем для совместимости с библиотекой STL для соответсвия заданию
    using iterator_category =
        std::forward_iterator_tag;  // Категория итератора (вперед)
    using value_type = data_type;  // Тип элементов дерева
    using reference = MRBTree::reference;  // Тип ссылки на элемент
    using pointer = MRBTree::pointer;  // Тип указателя на элемент
    using difference_type =
        std::ptrdiff_t;  // Тип для представления разницы между итераторами

    // Конструктор по умолчанию запрещен, так как итератор должен быть
    // инициализирован узлом
    ConstTreeIterator() = delete;

    // Конструктор, инициализирующий итератор указанным узлом
    explicit ConstTreeIterator(TreeNode *node) : current_(node) {}

    // Возвращает ссылку на значение текущего узла
    reference operator*() { return current_->data_; }

    // Операторы сравнения
    friend bool operator==(const TreeNode &lhs, const TreeNode &rhs) {
      return lhs.key_ == rhs.key_;
    }

    friend bool operator!=(const TreeNode &lhs, const TreeNode &rhs) {
      return !(lhs == rhs);
    }

    // Перемещает итератор к следующему узлу в дереве
    ConstTreeIterator &operator++() noexcept {
      if (current_->right_) {
        current_ = current_->right_;
        while (current_->left_ != nullptr) {
          current_ = current_->left_;
        }
      } else {
        while (current_->parent_ && current_->parent_->right_ == current_) {
          current_ = current_->parent_;
        }

        // Достигли конца дерева
        if (!current_->parent_) {
          current_ = nullptr;
        } else {
          current_ = current_->parent_;
        }
      }
      return *this;
    }

    // Перемещает итератор к предыдущему узлу в дереве
    ConstTreeIterator &operator--() noexcept {
      if (current_->left_) {
        current_ = current_->left_;
        while (current_->right_ != nullptr) {
          current_ = current_->right_;
        }
      } else {
        while (current_->parent_ && current_->parent_->left_ == current_) {
          current_ = current_->parent_;
        }

        // Достигли начала дерева
        if (!current_->parent_) {
          current_ = nullptr;
        } else {
          current_ = current_->parent_;
        }
      }
      return *this;
    }

    // Проверяет итераторы на равенство
    bool operator==(const ConstTreeIterator &other) const noexcept {
      return current_ == other.current_;
    }

    // Проверяет итераторы на неравенство
    bool operator!=(const ConstTreeIterator &other) const noexcept {
      return current_ != other.current_;
    }

    // Возвращает указатель на текущий узел
    TreeNode *get_node() { return current_; }

    // Возвращает ключ где находится итератор
    const key_type &key() const {
      if (current_ == nullptr) {
        throw std::out_of_range("Iterator is out of range");
      }
      return current_->key_;
    }
    // Возвращает значение где находится итератор
    const data_type &data() const {
      if (current_ == nullptr) {
        throw std::out_of_range("Iterator is out of range");
      }
      return current_->data_;
    }

   private:
    const TreeNode *current_;  // Указатель на текущий узел
  };

  //////////////////////////////// итератор ////////////////////////////////
  class TreeIterator {
   public:
    // переназначаем для совместимости с библиотекой STL для соответсвия заданию
    using iterator_category = std::forward_iterator_tag;
    using value_type = data_type;
    using difference_type = std::ptrdiff_t;
    using pointer = data_type *;
    using reference = data_type &;
    // Конструктор по умолчанию запрещен, так как итератор должен быть
    // инициализирован узлом
    TreeIterator() = delete;

    // Конструктор, инициализирующий итератор указанным узлом
    explicit TreeIterator(TreeNode *node) : current_(node) {}

    // Возвращает ссылку на значение текущего узла
    reference operator*() { return current_->data_; }

    // Перемещает итератор к следующему узлу в дереве
    // Перемещает итератор к следующему узлу в дереве
    TreeIterator &operator++() noexcept {
      if (current_->right_) {
        current_ = current_->right_;
        while (current_->left_ != nullptr) {
          current_ = current_->left_;
        }
      } else {
        while (current_->parent_ && current_->parent_->right_ == current_) {
          current_ = current_->parent_;
        }

        // Достигли конца дерева
        if (!current_->parent_) {
          current_ = nullptr;
        } else {
          current_ = current_->parent_;
        }
      }
      return *this;
    }

    // Перемещает итератор к предыдущему узлу в дереве
    TreeIterator &operator--() noexcept {
      if (current_->left_) {
        current_ = current_->left_;
        while (current_->right_ != nullptr) {
          current_ = current_->right_;
        }
      } else {
        while (current_->parent_ && current_->parent_->left_ == current_) {
          current_ = current_->parent_;
        }

        // Достигли начала дерева
        if (!current_->parent_) {
          current_ = nullptr;
        } else {
          current_ = current_->parent_;
        }
      }
      return *this;
    }

    // Проверяет итераторы на равенство
    bool operator==(const TreeIterator &other) const noexcept {
      return current_ == other.current_;
    }

    // Проверяет итераторы на неравенство
    bool operator!=(const TreeIterator &other) const noexcept {
      return current_ != other.current_;
    }

    // Возвращает указатель на текущий узел
    TreeNode *get_node() { return current_; }

    // Возвращает ключ где находится итератор
    const key_type &key() const {
      if (current_ == nullptr) {
        throw std::out_of_range("Iterator is out of range");
      }
      return current_->key_;
    }
    // Возвращает значение где находится итератор
    const data_type &data() const {
      if (current_ == nullptr) {
        throw std::out_of_range("Iterator is out of range");
      }
      return current_->data_;
    }

   private:
    TreeNode *current_;  // Указатель на текущий узел
  };

  //////////////////////////// приватные методы ////////////////////////////
 private:
  // Рекурсивная функция для подсчета количества элементов с определенным ключом
  size_type countRecursive(TreeNode *current, const Key &key) const {
    if (current == nullptr) {
      return 0;
    }

    size_type count = 0;

    if (key == current->key_) {
      ++count;
    }

    count += countRecursive(current->left_, key);
    count += countRecursive(current->right_, key);

    return count;
  }

  TreeNode *findLeftmost(TreeNode *node) const {
    if (node == nullptr) return nullptr;

    while (node->left_ != nullptr) {
      node = node->left_;
    }

    return node;
  }

  // Вспомогательный метод для поиска ноды
  TreeNode *findNode(const key_type &key) const {
    TreeNode *current = root_;
    while (current != nullptr) {
      if (key < current->key_) {
        current = current->left_;
      } else if (key > current->key_) {
        current = current->right_;
      } else {
        return current;  // Узел найден
      }
    }
    return nullptr;  // Узел не найден
  }
  // Вспомогательный метод для обычной вставки в дерево
  void insertNode(TreeNode *newNode) {
    TreeNode *current = root_;
    TreeNode *parent = nullptr;

    // Ищем место для вставки узла
    while (current != nullptr) {
      parent = current;
      if (newNode->key_ < current->key_) {
        current = current->left_;
      } else {
        current = current->right_;
      }
    }
    // Вставляем узел в дерево
    newNode->parent_ = parent;
    if (parent == nullptr) {
      // Вставка в пустое дерево
      root_ = newNode;
    } else if (newNode->key_ < parent->key_) {
      parent->left_ = newNode;
    } else {
      parent->right_ = newNode;
    }
    // Увеличиваем размер дерева
    size_++;
  }

  // метод балансировки после вставки
  void fixInsertion(TreeNode *node) {
    while (node != root_ && node->parent_ &&
           node->parent_->color_ == Color::RED) {
      TreeNode *parent = node->parent_;
      TreeNode *grandparent = parent->parent_;

      if (!grandparent) {
        break;  // Нет дедушки выход из цикла
      }

      TreeNode *uncle = (parent == grandparent->left_) ? grandparent->right_
                                                       : grandparent->left_;

      if (uncle && uncle->color_ == Color::RED) {
        grandparent->color_ = Color::RED;
        parent->color_ = Color::BLACK;
        uncle->color_ = Color::BLACK;
        node = grandparent;
      } else {
        if (parent == grandparent->left_) {
          if (node == parent->right_) {
            node = parent;
            RotateLeft(node);
          }

          parent->color_ = Color::BLACK;
          grandparent->color_ = Color::RED;
          RotateRight(grandparent);
        } else {
          if (node == parent->left_) {
            node = parent;
            RotateRight(node);
          }

          parent->color_ = Color::BLACK;
          grandparent->color_ = Color::RED;
          RotateLeft(grandparent);
        }
      }
    }
    root_->color_ = Color::BLACK;
  }

  /* Метод выполняет операцию правого поворота в красно-черном дереве.
    Эта операция меняет структуру дерева таким образом, что
   узел становится правым потомком своего левого потомка.*/
  void RotateRight(TreeNode *node) {
    TreeNode *leftChild = node->left_;
    node->left_ = leftChild->right_;

    if (leftChild->right_ != nullptr) {
      leftChild->right_->parent_ = node;
    }

    leftChild->parent_ = node->parent_;

    if (node->parent_ == nullptr) {
      root_ = leftChild;
    } else if (node == node->parent_->left_) {
      node->parent_->left_ = leftChild;
    } else {
      node->parent_->right_ = leftChild;
    }

    leftChild->right_ = node;
    node->parent_ = leftChild;
  }

  /*Метод выполняет операцию левого поворота в красно-черном дереве.
  Она изменяет структуру дерева таким образом,
  что узел становится левым потомком своего правого потомка.*/
  void RotateLeft(TreeNode *node) {
    TreeNode *rightChild = node->right_;
    node->right_ = rightChild->left_;

    if (rightChild->left_ != nullptr) {
      rightChild->left_->parent_ = node;
    }

    rightChild->parent_ = node->parent_;

    if (node->parent_ == nullptr) {
      root_ = rightChild;
    } else if (node == node->parent_->left_) {
      node->parent_->left_ = rightChild;
    } else {
      node->parent_->right_ = rightChild;
    }

    rightChild->left_ = node;
    node->parent_ = rightChild;
  }

  void removeNode(TreeNode *nodeToRemove) {
    // Находим узел для замены
    TreeNode *replacementNode =
        (nodeToRemove->left_ == nullptr || nodeToRemove->right_ == nullptr)
            ? nodeToRemove
            : findSuccessor(nodeToRemove);

    // Определяем потомка для замены
    TreeNode *childNode = (replacementNode->left_ != nullptr)
                              ? replacementNode->left_
                              : replacementNode->right_;

    // Устанавливаем parent у потомка
    if (childNode != nullptr) {
      childNode->parent_ = replacementNode->parent_;
    }

    // Поднимаем потомка на уровень удаляемого узла
    if (replacementNode->parent_ == nullptr) {
      // Если удаляемый узел - корень
      root_ = childNode;
    } else {
      if (replacementNode == replacementNode->parent_->left_) {
        replacementNode->parent_->left_ = childNode;
      } else {
        replacementNode->parent_->right_ = childNode;
      }
    }

    if (replacementNode != nodeToRemove) {
      // Копируем значения заменяемого узла в удаляемый
      nodeToRemove->key_ = replacementNode->key_;
      nodeToRemove->data_ = replacementNode->data_;
    }

    // Если цвет заменяемого узла черный, восстанавливаем баланс
    if (replacementNode->color_ == Color::BLACK) {
      fixDoubleBlack(childNode, replacementNode->parent_);
    }

    // Освобождаем память для заменяемого узла
    delete replacementNode;
    size_--;
  }

  TreeNode *findSuccessor(TreeNode *node) {
    // Если у узла есть правое поддерево, то следующим будет самый левый узел в
    // этом поддереве
    if (node->right_ != nullptr) {
      return findMinimum(node->right_);
    }

    // Иначе, следующим узлом будет первый предок узла, через который можно
    // достичь узла слева
    TreeNode *parent = node->parent_;
    while (parent != nullptr && node == parent->right_) {
      node = parent;
      parent = parent->parent_;
    }

    return parent;
  }

  TreeNode *findMinimum(TreeNode *node) {
    // Находим самый левый узел в дереве
    while (node->left_ != nullptr) {
      node = node->left_;
    }
    return node;
  }

  void fixDoubleBlack(TreeNode *childNode, TreeNode *parent) {
    TreeNode *sibling;
    while ((childNode == nullptr || childNode->color_ == Color::BLACK) &&
           childNode != root_) {
      if (childNode == parent->left_) {
        sibling = parent->right_;
        if (sibling->color_ == Color::RED) {
          // Случай 1: Брат красный
          sibling->color_ = Color::BLACK;
          parent->color_ = Color::RED;
          RotateLeft(parent);
          sibling = parent->right_;
        }

        if ((sibling->left_ == nullptr ||
             sibling->left_->color_ == Color::BLACK) &&
            (sibling->right_ == nullptr ||
             sibling->right_->color_ == Color::BLACK)) {
          // Случай 2: Брат и его дети черные
          sibling->color_ = Color::RED;
          childNode = parent;
          parent = childNode->parent_;
        } else {
          if (sibling->right_ == nullptr ||
              sibling->right_->color_ == Color::BLACK) {
            // Случай 3: брат — черный, левый сын брата — красный, а
            // правый сын брата черный
            sibling->left_->color_ = Color::BLACK;
            sibling->color_ = Color::RED;
            RotateRight(sibling);
            sibling = parent->right_;
          }

          // Случай 4: Брат черный, правый ребенок брата красный.
          sibling->color_ = parent->color_;
          parent->color_ = Color::BLACK;
          sibling->right_->color_ = Color::BLACK;
          RotateLeft(parent);
          childNode = root_;
          break;
        }
      } else {
        // Симметричные случаи для правого поддерева
        sibling = parent->left_;
        if (sibling->color_ == Color::RED) {
          sibling->color_ = Color::BLACK;
          parent->color_ = Color::RED;
          RotateRight(parent);
          sibling = parent->left_;
        }

        if ((sibling->right_ == nullptr ||
             sibling->right_->color_ == Color::BLACK) &&
            (sibling->left_ == nullptr ||
             sibling->left_->color_ == Color::BLACK)) {
          sibling->color_ = Color::RED;
          childNode = parent;
          parent = childNode->parent_;
        } else {
          if (sibling->left_ == nullptr ||
              sibling->left_->color_ == Color::BLACK) {
            sibling->right_->color_ = Color::BLACK;
            sibling->color_ = Color::RED;
            RotateLeft(sibling);
            sibling = parent->left_;
          }

          sibling->color_ = parent->color_;
          parent->color_ = Color::BLACK;
          sibling->left_->color_ = Color::BLACK;
          RotateRight(parent);
          childNode = root_;
          break;
        }
      }
    }

    if (childNode != nullptr) {
      childNode->color_ = Color::BLACK;
    }
  }

  // Вспомогательный метод для рекурсивного копирования узлов дерева
  TreeNode *copyTree(const TreeNode *srcNode, TreeNode *parent) {
    if (!srcNode) {
      return nullptr;
    }
    // Копируем текущий узел
    TreeNode *newNode =
        new TreeNode(srcNode->key_, srcNode->data_, srcNode->color_);
    newNode->parent_ = parent;
    // Рекурсивно копируем левое и правое поддерево
    newNode->left_ = copyTree(srcNode->left_, newNode);
    newNode->right_ = copyTree(srcNode->right_, newNode);
    return newNode;
  }

  // Вспомогательный метод для поиска узла с минимальным ключом
  TreeNode *findMin(TreeNode *node) {
    while (node && node->left_) {
      node = node->left_;
    }
    return node;
  }

  // Рекурсивный метод для очистки дерева
  void clearRecursive(TreeNode *node) {
    if (node) {
      clearRecursive(node->left_);
      clearRecursive(node->right_);
      delete node;
    }
  }

  TreeNode *root_;
  size_type size_ = 0;
};
}  // namespace s21

#endif  // RB_TREE_H
