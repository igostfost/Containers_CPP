#include <gtest/gtest.h>

#include <list>

#include "../s21_containers.h"

// Тестирование конструктора по умолчанию
TEST(List, Constructor_Default) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}

// Тестирование конструктора с размером
TEST(List, Constructor_Size) {
  s21::list<int> s21_list(5);
  std::list<int> std_list(5);
  EXPECT_EQ(s21_list.size(), std_list.size());
}

// Тестирование конструктора с initializer_list
TEST(List, Constructor_InitializerList) {
  s21::list<int> s21_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  EXPECT_EQ(s21_list.size(), std_list.size());
}

// Тестирование методов front и back
TEST(List, FrontBack) {
  s21::list<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};

  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

// Тестирование метода push_back
TEST(List, PushBack) {
  s21::list<int> s21_list;
  std::list<int> std_list;

  s21_list.push_back(1);
  std_list.push_back(1);

  s21_list.push_back(2);
  std_list.push_back(2);

  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

// Тестирование итераторов
TEST(List, Iterators) {
  s21::list<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};

  auto s21_it = s21_list.begin();
  auto std_it = std_list.begin();

  for (; s21_it != s21_list.end() && std_it != std_list.end();
       ++s21_it, ++std_it) {
    EXPECT_EQ(*s21_it, *std_it);
  }
}

// Тест на исключения
TEST(List, Exceptions) {
  s21::list<int> s21_list;
  EXPECT_THROW(s21_list.front(), std::out_of_range);
  EXPECT_THROW(s21_list.back(), std::out_of_range);
}

// Тест на большое количество элементов
TEST(List, LargeSize) {
  const int N = 100000;
  s21::list<int> s21_list(N);
  EXPECT_EQ(static_cast<int>(s21_list.size()), N);
}

TEST(List, Insert_Begin) {
  s21::list<int> s21_list = {2, 3, 4};
  std::list<int> std_list = {2, 3, 4};

  s21_list.insert(s21_list.begin(), 1);
  std_list.insert(std_list.begin(), 1);

  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.front(), std_list.front());
}

TEST(List, Insert_Middle) {
  s21::list<int> s21_list = {1, 3, 4};
  std::list<int> std_list = {1, 3, 4};

  auto s21_it = s21_list.begin();
  auto std_it = std_list.begin();
  ++s21_it;
  ++std_it;  // Переходим к второму элементу

  s21_list.insert(s21_it, 2);
  std_list.insert(std_it, 2);

  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(List, Insert_End) {
  s21::list<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};

  s21_list.insert(s21_list.end(), 4);
  std_list.insert(std_list.end(), 4);

  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(List, Insert_EmptyList) {
  s21::list<int> s21_list;
  std::list<int> std_list;

  s21_list.insert(s21_list.begin(), 1);
  std_list.insert(std_list.begin(), 1);

  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(List, Erase_Begin) {
  s21::list<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};

  s21_list.erase(s21_list.begin());
  std_list.erase(std_list.begin());

  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.front(), std_list.front());
}

TEST(List, Erase_Middle) {
  s21::list<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};

  auto s21_it = ++s21_list.begin();
  auto std_it = ++std_list.begin();

  s21_list.erase(s21_it);
  std_list.erase(std_it);

  EXPECT_EQ(s21_list.size(), std_list.size());
}

// Удаление последнего элемента в списке из одного элемента
TEST(List, Erase_SingleElement) {
  s21::list<int> s21_list = {1};
  std::list<int> std_list = {1};
  s21_list.erase(s21_list.begin());
  std_list.erase(std_list.begin());
  EXPECT_EQ(s21_list.size(), std_list.size());
}

// Удаление из непустого списка
TEST(List, PopBack_NonEmpty) {
  s21::list<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};

  s21_list.pop_back();
  std_list.pop_back();

  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

// Удаление из списка с одним элементом
TEST(List, PopBack_SingleElement) {
  s21::list<int> s21_list = {1};
  std::list<int> std_list = {1};

  s21_list.pop_back();
  std_list.pop_back();

  EXPECT_EQ(s21_list.size(), std_list.size());
}

// Добавление в пустой список
TEST(List, PushFront_EmptyList) {
  s21::list<int> s21_list;
  s21_list.push_front(1);
  EXPECT_EQ(s21_list.front(), 1);
  EXPECT_EQ(s21_list.back(), 1);
}

// Добавление в непустой список
TEST(List, PushFront_NonEmptyList) {
  s21::list<int> s21_list = {2, 3};
  s21_list.push_front(1);
  EXPECT_EQ(s21_list.front(), 1);
}

TEST(List, Merge_SortedLists) {
  s21::list<int> list1 = {1, 3, 5};
  s21::list<int> list2 = {2, 4, 6};

  list1.merge(list2);

  std::list<int> expected = {1, 2, 3, 4, 5, 6};
  auto it = list1.begin();

  for (const auto& exp : expected) {
    EXPECT_EQ(exp, *it);
    ++it;
  }
}

TEST(List, Merge_EmptyList) {
  s21::list<int> list1 = {1, 2, 3};
  s21::list<int> list2;

  list1.merge(list2);

  std::list<int> expected = {1, 2, 3};
  auto it = list1.begin();

  for (const auto& exp : expected) {
    EXPECT_EQ(exp, *it);
    ++it;
  }
}

TEST(List, Merge_IntoEmptyList) {
  s21::list<int> list1;
  s21::list<int> list2 = {1, 2, 3};

  list1.merge(list2);

  std::list<int> expected = {1, 2, 3};
  auto it = list1.begin();

  for (const auto& exp : expected) {
    EXPECT_EQ(exp, *it);
    ++it;
  }
}

TEST(List, Merge_IdenticalLists) {
  s21::list<int> list1 = {1, 2, 3};
  s21::list<int> list2 = {1, 2, 3};

  list1.merge(list2);

  std::list<int> expected = {1, 1, 2, 2, 3, 3};
  auto it = list1.begin();

  for (const auto& exp : expected) {
    EXPECT_EQ(exp, *it);
    ++it;
  }
}

TEST(List, Reverse_NonEmptyList) {
  s21::list<int> list1 = {1, 2, 3};
  list1.reverse();

  std::list<int> expected = {3, 2, 1};
  auto it = list1.begin();

  for (const auto& exp : expected) {
    EXPECT_EQ(exp, *it);
    ++it;
  }
}

TEST(List, Reverse_EmptyList) {
  s21::list<int> list1;
  list1.reverse();  // Должно работать без ошибок

  EXPECT_TRUE(list1.empty());
}

TEST(List, Reverse_SingleElement) {
  s21::list<int> list1 = {1};
  list1.reverse();

  EXPECT_EQ(1, list1.front());
}

TEST(List, Splice_IntoEmpty) {
  s21::list<int> s21_list;
  s21::list<int> other = {1, 2, 3};
  std::list<int> std_list;
  std::list<int> std_other = {1, 2, 3};

  s21_list.splice(s21_list.c_begin(), other);
  std_list.splice(std_list.begin(), std_other);

  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(List, Splice_AtBeginning) {
  s21::list<int> s21_list = {4, 5, 6};
  s21::list<int> other = {1, 2, 3};
  std::list<int> std_list = {4, 5, 6};
  std::list<int> std_other = {1, 2, 3};

  s21_list.splice(s21_list.c_begin(), other);
  std_list.splice(std_list.begin(), std_other);

  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(List, Splice_AtEnd) {
  s21::list<int> s21_list = {1, 2, 3};
  s21::list<int> other = {4, 5, 6};
  std::list<int> std_list = {1, 2, 3};
  std::list<int> std_other = {4, 5, 6};

  s21_list.splice(s21_list.c_end(), other);
  std_list.splice(std_list.end(), std_other);

  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(List, Unique_EmptyList) {
  s21::list<int> s21_list;
  std::list<int> std_list;

  s21_list.unique();
  std_list.unique();

  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(List, Unique_SingleElement) {
  s21::list<int> s21_list = {1};
  std::list<int> std_list = {1};

  s21_list.unique();
  std_list.unique();

  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(List, Unique_MultipleElements) {
  s21::list<int> s21_list = {1, 1, 2, 2, 2, 3, 4, 4, 5};
  std::list<int> std_list = {1, 1, 2, 2, 2, 3, 4, 4, 5};

  s21_list.unique();
  std_list.unique();

  EXPECT_EQ(s21_list.size(), std_list.size());

  auto s21_it = s21_list.begin();
  auto std_it = std_list.begin();
  while (s21_it != ++s21_list.end() && std_it != std_list.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(List, Front_OnEmptyList) {
  s21::list<int> lst;

  EXPECT_THROW(lst.front(), std::out_of_range);
}

TEST(List, Back_OnEmptyList) {
  s21::list<int> lst;

  EXPECT_THROW(lst.back(), std::out_of_range);
}

TEST(List, Front_OnNonEmptyList) {
  s21::list<int> lst{1, 2, 3, 4, 5};

  EXPECT_EQ(lst.front(), 1);
}

TEST(List, Back_OnNonEmptyList) {
  s21::list<int> lst{1, 2, 3, 4, 5};

  EXPECT_EQ(lst.back(), 5);
}

TEST(ListConstIterator, Dereference_ValidIterator) {
  s21::list<int> lst{1, 2, 3, 4, 5};
  auto it = lst.c_begin();

  EXPECT_EQ(*it, 1);
}

TEST(ListConstIterator, Increment) {
  s21::list<int> lst{1, 2, 3, 4, 5};
  auto it = lst.c_begin();

  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(ListConstIterator, Decrement) {
  s21::list<int> lst{1, 2, 3, 4, 5};
  auto it = lst.c_end();
  EXPECT_EQ(*it, 5);
}

TEST(ListConstIterator, Equality) {
  s21::list<int> lst{1, 2, 3, 4, 5};
  auto it1 = lst.c_begin();
  auto it2 = lst.c_begin();

  EXPECT_TRUE(it1 == it2);
}

TEST(ListConstIterator, Inequality) {
  s21::list<int> lst{1, 2, 3, 4, 5};
  auto it1 = lst.c_begin();
  auto it2 = ++lst.c_begin();

  EXPECT_TRUE(it1 != it2);
}

TEST(List, Front_ValidList) {
  s21::list<int> lst{1, 2, 3, 4, 5};
  EXPECT_EQ(lst.front(), 1);
}

TEST(List, Front_EmptyList) {
  s21::list<int> lst;

  EXPECT_THROW(lst.front(), std::out_of_range);
}

TEST(List, Swap) {
  s21::list<int> list1{1, 2, 3};
  s21::list<int> list2{4, 5, 6, 7};

  list1.swap(list2);

  // Проверяем размеры списков после swap
  EXPECT_EQ(list1.size(), 4UL);
  EXPECT_EQ(list2.size(), 3UL);
}

TEST(List, Merge) {
  s21::list<int> list1{1, 3, 5};
  s21::list<int> list2{2, 4, 6};

  s21::list<int> mainList;
  mainList.merge(list1);
  mainList.merge(list2);

  // Проверяем размер объединенного списка
  EXPECT_EQ(mainList.size(), 6UL);

  // Проверяем содержимое объединенного списка с помощью итераторов
  auto it = mainList.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(ListTest, SortTest) {
  s21::list<int> myList;

  // Заполняем список неотсортированными данными.
  myList.push_back(5);
  myList.push_back(3);
  myList.push_back(8);
  myList.push_back(1);
  myList.push_back(4);

  // Сортируем список.
  myList.sort();
  // Проверяем, правильно ли отсортирован список, используя итераторы.
  auto it = myList.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 4);
  ++it;
  EXPECT_EQ(*it, 5);
  ++it;
  EXPECT_EQ(*it, 8);
}

TEST(ListTest, MoveAssignmentWithNonEmptyList) {
  // Создаем два списка
  s21::list<int> list1;
  s21::list<int> list2;

  list1.push_back(1);
  list1.push_back(2);
  list1.push_back(3);

  list2 = std::move(list1);

  EXPECT_EQ(list2.size(), 3UL);
  EXPECT_EQ(list1.size(), 0UL);
}

TEST(ListIterator, IteratorEnd) {
  s21::list<int> myList;
  myList.push_back(1);
  myList.push_back(2);
  myList.push_back(3);

  auto it = myList.end();
  EXPECT_EQ(*it, 3);
}

TEST(ListIterator, IteratorBegin) {
  s21::list<int> myList;
  myList.push_back(1);
  myList.push_back(2);
  myList.push_back(3);

  auto it = myList.begin();
  EXPECT_EQ(*it, 1);
}