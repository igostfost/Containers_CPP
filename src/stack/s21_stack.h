#include <iostream>

template <typename u>
struct rebind {
  using other = std::allocator<u>;
};

template <typename T, typename Alloc = std::allocator<T>>
class Stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;
  // Конструкторы
  Stack();
  Stack(std::initializer_list<value_type> const &items);
  Stack(const Stack &s);
  Stack(Stack &&s);
  Stack &operator=(Stack &&other);
  Stack &operator=(const Stack &other);
  ~Stack();
  // Основные методы
  void push(value_type new_element);
  void pop();
  bool empty();
  void swap(Stack &other);
  size_type size() const;
  const_reference top();
  // Дополнительные методы
  void copy_helper(const Stack &s);

 private:
  size_type count_of_elements;
  typedef struct Node {
    value_type data;
    Node *next;
  } Node;
  using NodeAlloc =
      typename std::allocator_traits<Alloc>::template rebind_alloc<Node>;
  NodeAlloc alloc_node_;
  Alloc alloc;
  Node *list;
};

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------Конструкторы------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Конструктор по умолчанию
template <typename T, typename Alloc>
Stack<T, Alloc>::Stack()
    : count_of_elements(0), list(nullptr) {}  // Конструктор по умолчанию

// Конструктор со списком инициализации
template <typename T, typename Alloc>
Stack<T, Alloc>::Stack(std::initializer_list<value_type> const &items)
    : count_of_elements(0), list(nullptr) {
  for (auto i = items.begin(); i < items.end(); ++i) {
    push(*i);
  }
}

// Конструктор копирования
template <typename T, typename Alloc>
Stack<T, Alloc>::Stack(const Stack &s) : count_of_elements(0), list(nullptr) {
  copy_helper(s);
}

// Конструктор перемещения
template <typename T, typename Alloc>
Stack<T, Alloc>::Stack(Stack &&s)
    : count_of_elements(s.count_of_elements), list(s.list) {
  s.list = nullptr;
  s.count_of_elements = 0;
}

template <typename T, typename Alloc>
Stack<T, Alloc> &Stack<T, Alloc>::operator=(Stack &&other) {
  if (this != &other) {
    Stack new_stack(std::move(other));
    swap(new_stack);
  }

  return *this;
}

template <typename T, typename Alloc>
Stack<T, Alloc> &Stack<T, Alloc>::operator=(const Stack &other) {
  if (this != &other) {
    while (!empty()) {
      pop();
    }
    copy_helper(other);
  }
  return *this;
}

// Деструктор
template <typename T, typename Alloc>
Stack<T, Alloc>::~Stack() {
  while (list != nullptr) {
    Node *temp = list;
    list = temp->next;
    if (temp != nullptr && &(temp->data) != nullptr) {
      std::allocator_traits<NodeAlloc>::destroy(alloc_node_, temp);
      std::allocator_traits<NodeAlloc>::deallocate(alloc_node_, temp,
                                                   sizeof(Node));
    }
  }
  count_of_elements = 0;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------Основные
// методы---------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template <typename T, typename Alloc>
void Stack<T, Alloc>::push(value_type new_element) {
  Node *p = std::allocator_traits<NodeAlloc>::allocate(alloc_node_, 1);
  p->data = new_element;
  p->next = list;
  list = p;
  count_of_elements++;
}

template <typename T, typename Alloc>
void Stack<T, Alloc>::pop() {
  Node *p = list;
  list = p->next;
  std::allocator_traits<NodeAlloc>::destroy(alloc_node_, p);
  std::allocator_traits<NodeAlloc>::deallocate(alloc_node_, p, sizeof(Node));
  count_of_elements--;
}

template <typename T, typename Alloc>
bool Stack<T, Alloc>::empty() {
  bool res = false;
  if (list == nullptr) {
    res = true;
  }
  return res;
}

template <typename T, typename Alloc>
void Stack<T, Alloc>::swap(Stack &other) {
  std::swap(list, other.list);
  std::swap(count_of_elements, other.count_of_elements);
}

template <typename T, typename Alloc>
typename Stack<T, Alloc>::size_type Stack<T, Alloc>::size() const {
  return count_of_elements;
}

template <typename T, typename Alloc>
typename Stack<T, Alloc>::const_reference Stack<T, Alloc>::top() {
  return list->data;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------Дополнительные
// методы---------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template <typename T, typename Alloc>
void Stack<T, Alloc>::copy_helper(const Stack &s) {
  Node *current = s.list;
  Stack<size_t> a;
  while (current) {
    a.push(current->data);
    current = current->next;
  }
  while (a.list) {
    push(a.list->data);
    a.pop();
  }
}
