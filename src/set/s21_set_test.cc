#include <gtest/gtest.h>

#include <set>
#include <string>

#include "../s21_containers.h"

// Тест вставки и проверки размера дерева
TEST(RBTreeTest, InsertAndSize) {
  s21::RBTree<int, std::string> myTree;
  myTree.insert(1, "one");
  myTree.insert(2, "two");
  myTree.insert(3, "three");

  EXPECT_EQ(myTree.size(), 3u);
}

TEST(RBTreeTest, InsertAndSize1) {
  s21::RBTree<int, std::string> myTree;
  myTree.insert(1, "one");
  myTree.insert(1, "two");
  myTree.insert(3, "three");

  EXPECT_EQ(myTree.size(), 2u);
}

// Тест удаления элемента и проверки размера дерева
TEST(RBTreeTest, eraseAndSize) {
  s21::RBTree<int, std::string> myTree{{1, "one"}, {2, "two"}, {3, "three"}};

  myTree.erase(2);

  EXPECT_EQ(myTree.size(), 2u);
  EXPECT_EQ(myTree.find(2), nullptr);  // Узел должен быть удален
}

TEST(RBTreeTest, erase2) {
  s21::RBTree<int, std::string> myTree{
      {200, "one"},   {100, "two"},   {300, "three"}, {555, "one"},
      {22, "two"},    {333, "three"}, {111, "one"},   {23, "two"},
      {334, "three"}, {112, "one"},   {25, "two"},    {336, "three"},
      {145, "one"},   {19, "two"},    {376, "three"}, {147, "one"},
      {13, "two"},    {370, "three"}, {102, "one"},   {9, "two"},
      {399, "three"}};

  myTree.erase(399);

  EXPECT_EQ(myTree.size(), 20u);
  EXPECT_EQ(myTree.find(399), nullptr);  // Узел должен быть удален
}

TEST(RBTreeTest, erase3) {
  s21::RBTree<int, std::string> myTree{
      {200, "one"},   {100, "two"},   {300, "three"}, {555, "one"},
      {22, "two"},    {333, "three"}, {111, "one"},   {23, "two"},
      {334, "three"}, {112, "one"},   {25, "two"},    {336, "three"},
      {145, "one"},   {19, "two"},    {376, "three"}, {147, "one"},
      {13, "two"},    {370, "three"}, {102, "one"},   {9, "two"},
      {399, "three"}};

  myTree.erase(145);

  EXPECT_EQ(myTree.size(), 20u);
  EXPECT_EQ(myTree.find(145), nullptr);  // Узел должен быть удален
}

TEST(RBTreeTest, erase4) {
  s21::RBTree<int, std::string> myTree{
      {200, "one"},   {100, "two"},   {300, "three"}, {555, "one"},
      {22, "two"},    {333, "three"}, {111, "one"},   {23, "two"},
      {334, "three"}, {112, "one"},   {25, "two"},    {336, "three"},
      {145, "one"},   {19, "two"},    {376, "three"}, {147, "one"},
      {13, "two"},    {370, "three"}, {102, "one"},   {9, "two"},
      {399, "three"}};

  myTree.erase(200);

  EXPECT_EQ(myTree.size(), 20u);
  EXPECT_EQ(myTree.find(200), nullptr);  // Узел должен быть удален
}

TEST(RBTreeTest, erase5) {
  s21::RBTree<int, std::string> myTree{
      {200, "one"},   {100, "two"},   {300, "three"}, {555, "one"},
      {22, "two"},    {333, "three"}, {111, "one"},   {23, "two"},
      {334, "three"}, {112, "one"},   {25, "two"},    {336, "three"},
      {145, "one"},   {19, "two"},    {376, "three"}, {147, "one"},
      {13, "two"},    {370, "three"}, {102, "one"},   {9, "two"},
      {399, "three"}};

  myTree.erase(334);

  EXPECT_EQ(myTree.size(), 20u);
  EXPECT_EQ(myTree.find(334), nullptr);  // Узел должен быть удален
}

TEST(RBTreeTest, erase6) {
  s21::RBTree<int, std::string> myTree{
      {200, "one"},   {100, "two"},   {300, "three"}, {555, "one"},
      {22, "two"},    {333, "three"}, {111, "one"},   {23, "two"},
      {334, "three"}, {112, "one"},   {25, "two"},    {336, "three"},
      {145, "one"},   {19, "two"},    {376, "three"}, {147, "one"},
      {13, "two"},    {370, "three"}, {102, "one"},   {9, "two"},
      {399, "three"}};

  myTree.erase(23);

  EXPECT_EQ(myTree.size(), 20u);
  EXPECT_EQ(myTree.find(23), nullptr);  // Узел должен быть удален
}

TEST(RBTreeTest, erase7) {
  s21::RBTree<int, std::string> myTree{
      {200, "one"},   {100, "two"},   {300, "three"}, {555, "one"},
      {22, "two"},    {333, "three"}, {111, "one"},   {23, "two"},
      {334, "three"}, {112, "one"},   {25, "two"},    {336, "three"},
      {145, "one"},   {19, "two"},    {376, "three"}, {147, "one"},
      {13, "two"},    {370, "three"}, {102, "one"},   {9, "two"},
      {399, "three"}, {900, "two"},   {500, "three"}};

  myTree.erase(13);

  EXPECT_EQ(myTree.size(), 22u);
  EXPECT_EQ(myTree.find(13), nullptr);  // Узел должен быть удален
}

TEST(RBTreeTest, erase8) {
  s21::RBTree<int, std::string> myTree{{20, "one"}, {10, "two"}, {55, "three"},
                                       {50, "one"}, {53, "two"}, {66, "three"},
                                       {75, "one"}, {77, "two"}};

  myTree.erase(77);

  EXPECT_EQ(myTree.size(), 7u);
  EXPECT_EQ(myTree.find(77), nullptr);  // Узел должен быть удален
}

TEST(RBTreeTest, erase9) {
  s21::RBTree<int, int> myTree{
      {1, 1},   {2, 2},   {3, 3},   {4, 4},   {5, 5},   {6, 6},
      {7, 7},   {8, 8},   {9, 9},   {10, 10}, {11, 11}, {12, 12},
      {13, 13}, {14, 14}, {15, 15}, {16, 16}, {17, 17}, {18, 18},
      {19, 19}, {20, 20}, {21, 21}, {22, 22}, {23, 23}, {24, 24},
      {25, 25}, {26, 26}, {27, 27}, {28, 28}, {29, 29}, {30, 30}};

  myTree.erase(17);
  myTree.erase(19);
  myTree.erase(11);
  myTree.erase(12);

  EXPECT_EQ(myTree.size(), 26u);
}

TEST(RBTreeTest, erase10) {
  s21::RBTree<int, int> myTree{
      {1, 1},   {2, 2},   {3, 3},   {4, 4},   {5, 5},   {6, 6},
      {7, 7},   {8, 8},   {9, 9},   {10, 10}, {11, 11}, {12, 12},
      {13, 13}, {14, 14}, {15, 15}, {16, 16}, {17, 17}, {18, 18},
      {19, 19}, {20, 20}, {21, 21}, {22, 22}, {23, 23}, {24, 24},
      {25, 25}, {26, 26}, {27, 27}, {28, 28}, {29, 29}, {30, 30}};

  myTree.erase(17);
  myTree.erase(19);
  myTree.erase(11);
  myTree.erase(2);
  myTree.erase(1);
  myTree.erase(3);
  myTree.erase(5);
  myTree.erase(4);
  myTree.erase(21);
  myTree.erase(7);
  myTree.erase(9);
  myTree.erase(8);
  myTree.erase(6);
  myTree.erase(26);
  myTree.erase(25);
  myTree.erase(24);
  myTree.erase(18);
  myTree.erase(10);
  myTree.erase(12);
  myTree.erase(13);
  myTree.erase(14);
  myTree.erase(16);
  myTree.erase(15);
  myTree.erase(22);
  myTree.erase(23);
  myTree.erase(28);
  myTree.erase(29);
  myTree.erase(20);
  myTree.erase(27);
  myTree.erase(30);

  EXPECT_EQ(myTree.size(), 0u);
}

TEST(RBTreeTest, erase11) {
  s21::RBTree<int, int> myTree{
      {1, 1},   {2, 2},   {2, 2},   {2, 2},   {2, 2},   {2, 2},
      {7, 7},   {8, 8},   {9, 9},   {10, 10}, {11, 11}, {12, 12},
      {13, 13}, {14, 14}, {15, 15}, {16, 16}, {17, 17}, {18, 18},
      {19, 19}, {20, 20}, {21, 21}, {22, 22}, {23, 23}, {24, 24},
      {25, 25}, {26, 26}, {27, 27}, {28, 28}, {29, 29}, {30, 30}};

  myTree.erase(2);
  myTree.erase(17);
  myTree.erase(19);
  myTree.erase(11);
  myTree.erase(12);

  EXPECT_EQ(myTree.size(), 21u);
}

// Тест поиска элемента в дереве
TEST(RBTreeTest, Search) {
  s21::RBTree<int, std::string> myTree{{1, "one"}, {2, "two"}, {3, "three"}};

  auto foundNode = myTree.find(2);

  EXPECT_NE(foundNode, nullptr);  // Узел должен быть найден
  EXPECT_EQ(foundNode->key_, 2);
}

// Тест проверки на пустоту
TEST(RBTreeTest, Empty) {
  s21::RBTree<int, std::string> myTree;
  EXPECT_TRUE(myTree.empty());

  myTree.insert(42, "forty-two");
  EXPECT_FALSE(myTree.empty());

  myTree.clear();
  EXPECT_TRUE(myTree.empty());
}

// Тест максимального размера
TEST(RBTreeTest, MaxSize) {
  s21::RBTree<int, std::string> myTree;
  EXPECT_EQ(myTree.max_size(), std::numeric_limits<std::size_t>::max());
}

// Тест отчистки
TEST(RBTreeTest, Clear) {
  s21::RBTree<int, std::string> myTree{{1, "one"}, {2, "two"}, {3, "three"}};

  myTree.clear();
  EXPECT_TRUE(myTree.empty());
  EXPECT_EQ(myTree.size(), 0u);
}

// Тест метода проверки на содержание
TEST(RBTreeTest, Contains) {
  s21::RBTree<int, std::string> myTree{{1, "one"}, {2, "two"}, {3, "three"}};

  EXPECT_TRUE(myTree.contains(2));
  EXPECT_FALSE(myTree.contains(4));
}

// Тест методов итератора  конец/начало/итерации
TEST(RBTreeTest, BeginEnd) {
  s21::RBTree<int, std::string> myTree{{1, "one"}, {2, "two"}, {3, "three"}};

  auto it = myTree.begin();
  EXPECT_EQ(it.key(), 1);  // Используем функцию key() для ключа
  EXPECT_EQ(it.data(), "one");  // Используем функцию data() для значения

  ++it;
  EXPECT_EQ(it.key(), 2);
  EXPECT_EQ(it.data(), "two");

  ++it;
  EXPECT_EQ(it.key(), 3);
  EXPECT_EQ(it.data(), "three");

  ++it;
  EXPECT_EQ(it, myTree.end());
}

TEST(RBTreeTest, InsertAndContains) {
  s21::RBTree<int, std::string> myTree;

  // Вставляем элементы
  myTree.insert(1, "one");
  myTree.insert(2, "two");
  myTree.insert(4, "four");
  myTree.insert(3, "three");

  // Проверяем, содержатся ли элементы в дереве
  EXPECT_TRUE(myTree.contains(1));
  EXPECT_TRUE(myTree.contains(2));
  EXPECT_TRUE(myTree.contains(3));
  EXPECT_TRUE(myTree.contains(4));

  // Проверяем, что другие элементы отсутствуют
  EXPECT_FALSE(myTree.contains(5));
  EXPECT_FALSE(myTree.contains(6));
}

// Тест вставки и проверки размера сета
TEST(SetTest, InsertAndSize) {
  s21::Set<int> mySet;
  mySet.insert(1);
  mySet.insert(2);
  mySet.insert(3);

  EXPECT_EQ(mySet.size(), 3u);
}

// Тест удаления элемента и проверки размера сета
TEST(SetTest, RemoveAndSize) {
  s21::Set<int> mySet = {1, 2, 3};

  mySet.erase(2);

  EXPECT_EQ(mySet.size(), 2u);
  EXPECT_EQ(mySet.contains(2), false);
}

TEST(SetTest, Search) {
  s21::Set<int> mySet = {1, 2, 3};
  EXPECT_TRUE(mySet.find(1));
  EXPECT_TRUE(mySet.find(2));
  EXPECT_TRUE(mySet.find(3));
  EXPECT_FALSE(mySet.find(4));
}

// Тест проверки на пустоту
TEST(SetTest, Empty) {
  s21::Set<int> mySet;
  EXPECT_TRUE(mySet.empty());

  mySet.insert(42);
  EXPECT_FALSE(mySet.empty());

  mySet.clear();
  EXPECT_TRUE(mySet.empty());
}

// Тест максимального размера
TEST(SetTest, MaxSize) {
  s21::Set<int> mySet;
  EXPECT_EQ(mySet.max_size(), std::numeric_limits<std::size_t>::max());
}

// Тест отчистки
TEST(SetTest, Clear) {
  s21::Set<int> mySet = {1, 2, 3};

  mySet.clear();
  EXPECT_TRUE(mySet.empty());
  EXPECT_EQ(mySet.size(), 0u);
}

// Тест метода проверки на содержание
TEST(SetTest, Contains) {
  s21::Set<int> mySet = {1, 2, 3};

  EXPECT_TRUE(mySet.contains(2));
  EXPECT_FALSE(mySet.contains(4));
}

// Тест методов итератора: конец/начало/итерации
TEST(SetTest, BeginEnd) {
  s21::Set<int> mySet = {1, 2, 3};

  auto it = mySet.begin();
  EXPECT_EQ(*it, 1);

  ++it;
  EXPECT_EQ(*it, 2);

  ++it;
  EXPECT_EQ(*it, 3);

  ++it;
  EXPECT_EQ(it, mySet.end());
}

// Тест для сравнения s21::Set и std::set
TEST(SetComparisonTest, SameElements) {
  // Создаем и наполняем наш сет
  s21::Set<int> mySet = {1, 2, 3};

  // Создаем и наполняем std::set
  std::set<int> stdSet = {1, 2, 3};

  // Сравниваем размеры
  EXPECT_EQ(mySet.size(), stdSet.size());

  // Сравниваем содержимое
  EXPECT_TRUE(std::equal(mySet.begin(), mySet.end(), stdSet.begin()));
}

// Другие тесты сравнения могут включать сравнение операций вставки, удаления и
// т. д. Например:
TEST(SetComparisonTest, Insertion) {
  // Создаем наш сет
  s21::Set<int> mySet;

  // Вставляем элементы
  mySet.insert(1);
  mySet.insert(2);
  mySet.insert(3);

  // Создаем std::set и вставляем те же элементы
  std::set<int> stdSet;
  stdSet.insert(1);
  stdSet.insert(2);
  stdSet.insert(3);

  // Сравниваем размеры
  EXPECT_EQ(mySet.size(), stdSet.size());

  // Сравниваем содержимое
  EXPECT_TRUE(std::equal(mySet.begin(), mySet.end(), stdSet.begin()));
}

// Тест для сравнения метода contains у s21::Set и std::set
TEST(SetComparisonTest, Contains) {
  // Создаем и наполняем наш сет
  s21::Set<int> mySet = {1, 2, 3};

  // Создаем и наполняем std::set
  std::set<int> stdSet = {1, 2, 3};

  // Сравнение метода contains
  EXPECT_EQ(mySet.contains(2), stdSet.count(2) > 0);
}

// Тест для сравнения метода merge у s21::Set и std::set
TEST(SetComparisonTest, Merge) {
  // Создаем и наполняем наш сет
  s21::Set<int> mySet = {1, 2, 3};
  s21::Set<int> otherSet = {3, 4, 5};
  mySet.merge(otherSet);

  // Создаем и наполняем std::set
  std::set<int> stdSet = {1, 2, 3};
  std::set<int> otherStdSet = {3, 4, 5};
  stdSet.insert(otherStdSet.begin(), otherStdSet.end());

  // Сравнение размеров
  EXPECT_EQ(mySet.size(), stdSet.size());

  // Сравнение содержимого
  EXPECT_TRUE(std::equal(mySet.begin(), mySet.end(), stdSet.begin()));
}

// Тест для сравнения метода swap у s21::Set и std::set
TEST(SetComparisonTest, Swap) {
  // Создаем и наполняем наш сет
  s21::Set<int> mySet = {1, 2, 3};
  s21::Set<int> emptySet;

  // Создаем и наполняем std::set
  std::set<int> stdSet = {1, 2, 3};
  std::set<int> emptyStdSet;

  // Сравнение метода swap
  mySet.swap(emptySet);
  stdSet.swap(emptyStdSet);

  // Проверка, что оба сета после swap пусты
  EXPECT_TRUE(mySet.empty());
  EXPECT_FALSE(emptySet.empty());
  EXPECT_TRUE(stdSet.empty());
  EXPECT_FALSE(emptyStdSet.empty());
}

// Тест для сравнения метода erase у s21::Set и std::set
TEST(SetComparisonTest, Erase) {
  // Создаем и наполняем наш сет
  s21::Set<int> mySet = {1, 2, 3};

  // Создаем и наполняем std::set
  std::set<int> stdSet = {1, 2, 3};

  // Сравнение метода erase
  mySet.erase(2);
  stdSet.erase(2);

  // Сравнение размеров
  EXPECT_EQ(mySet.size(), stdSet.size());

  // Сравнение содержимого
  EXPECT_TRUE(std::equal(mySet.begin(), mySet.end(), stdSet.begin()));
}

// Тест для сравнения метода insert у s21::Set и std::set
TEST(SetComparisonTest, Insert) {
  // Создаем и наполняем наш сет
  s21::Set<int> mySet = {1, 2, 3};

  // Создаем и наполняем std::set
  std::set<int> stdSet = {1, 2, 3};

  // Сравнение метода insert
  mySet.insert(4);
  stdSet.insert(4);

  // Сравнение размеров
  EXPECT_EQ(mySet.size(), stdSet.size());

  // Сравнение содержимого
  EXPECT_TRUE(std::equal(mySet.begin(), mySet.end(), stdSet.begin()));
}

// Тест для сравнения метода insert у s21::Set и std::set
TEST(SetComparisonTest, Insert2) {
  // Создаем и наполняем наш сет
  s21::Set<int> mySet = {1, 2, 3};

  // Создаем и наполняем std::set
  std::set<int> stdSet = {1, 2, 3};

  // Сравнение метода insert
  mySet.insert(3);
  stdSet.insert(3);

  // Сравнение размеров
  EXPECT_EQ(mySet.size(), stdSet.size());

  // Сравнение содержимого
  EXPECT_TRUE(std::equal(mySet.begin(), mySet.end(), stdSet.begin()));
}
