#include <gtest/gtest.h>

#include <algorithm>
#include <set>

#include "../s21_containersplus.h"

// Тест вставки и проверки размера дерева
TEST(MRBTreeTest, InsertAndSize) {
  s21::MRBTree<int, std::string> myTree;
  myTree.insert(1, "one");
  myTree.insert(2, "two");
  myTree.insert(3, "three");

  EXPECT_EQ(myTree.size(), 3u);
}

// Тест удаления элемента и проверки размера дерева
TEST(MRBTreeTest, eraseAndSize) {
  s21::MRBTree<int, std::string> myTree{{1, "one"}, {2, "two"}, {3, "three"}};

  myTree.erase(2);

  EXPECT_EQ(myTree.size(), 2u);
  EXPECT_EQ(myTree.find(2), nullptr);  // Узел должен быть удален
}

// Тест поиска элемента в дереве
TEST(MRBTreeTest, Search) {
  s21::MRBTree<int, std::string> myTree{{1, "one"}, {2, "two"}, {3, "three"}};

  auto foundNode = myTree.find(2);

  EXPECT_NE(foundNode, nullptr);  // Узел должен быть найден
  EXPECT_EQ(foundNode->key_, 2);
}

TEST(MRBTreeTest, erase2) {
  s21::MRBTree<int, std::string> myTree{
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

TEST(MRBTreeTest, erase3) {
  s21::MRBTree<int, std::string> myTree{
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

TEST(MRBTreeTest, erase4) {
  s21::MRBTree<int, std::string> myTree{
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

TEST(MRBTreeTest, erase5) {
  s21::MRBTree<int, std::string> myTree{
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

TEST(MRBTreeTest, erase6) {
  s21::MRBTree<int, std::string> myTree{
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

TEST(MRBTreeTest, erase7) {
  s21::MRBTree<int, std::string> myTree{
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

TEST(MRBTreeTest, erase8) {
  s21::MRBTree<int, std::string> myTree{{20, "one"}, {10, "two"}, {55, "three"},
                                        {50, "one"}, {53, "two"}, {66, "three"},
                                        {75, "one"}, {77, "two"}};

  myTree.erase(77);

  EXPECT_EQ(myTree.size(), 7u);
  EXPECT_EQ(myTree.find(77), nullptr);  // Узел должен быть удален
}

TEST(MRBTreeTest, erase9) {
  s21::MRBTree<int, int> myTree{
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

TEST(MRBTreeTest, erase10) {
  s21::MRBTree<int, int> myTree{
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

TEST(MRBTreeTest, erase11) {
  s21::MRBTree<int, int> myTree{
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

// Тест проверки на пустоту
TEST(MRBTreeTest, Empty) {
  s21::MRBTree<int, std::string> myTree;
  EXPECT_TRUE(myTree.empty());

  myTree.insert(42, "forty-two");
  EXPECT_FALSE(myTree.empty());

  myTree.clear();
  EXPECT_TRUE(myTree.empty());
}

// Тест максимального размера
TEST(MRBTreeTest, MaxSize) {
  s21::MRBTree<int, std::string> myTree;
  EXPECT_EQ(myTree.max_size(), std::numeric_limits<std::size_t>::max());
}

// Тест отчистки
TEST(MRBTreeTest, Clear) {
  s21::MRBTree<int, std::string> myTree{{1, "one"}, {2, "two"}, {3, "three"}};

  myTree.clear();
  EXPECT_TRUE(myTree.empty());
  EXPECT_EQ(myTree.size(), 0u);
}

// Тест метода проверки на содержание
TEST(MRBTreeTest, Contains) {
  s21::MRBTree<int, std::string> myTree{{1, "one"}, {2, "two"}, {3, "three"}};

  EXPECT_TRUE(myTree.contains(2));
  EXPECT_FALSE(myTree.contains(4));
}

// Тест методов итератора  конец/начало/итерации
TEST(MRBTreeTest, BeginEnd) {
  s21::MRBTree<int, std::string> myTree{{1, "one"}, {2, "two"}, {3, "three"}};

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

TEST(MRBTreeTest, InsertAndContains) {
  s21::MRBTree<int, std::string> myTree;

  // Вставляем элементы
  myTree.insert(1, "one");
  myTree.insert(2, "two");
  myTree.insert(3, "three");

  // Проверяем, содержатся ли элементы в дереве
  EXPECT_TRUE(myTree.contains(1));
  EXPECT_TRUE(myTree.contains(2));
  EXPECT_TRUE(myTree.contains(3));

  // Проверяем, что другие элементы отсутствуют
  EXPECT_FALSE(myTree.contains(4));
  EXPECT_FALSE(myTree.contains(5));
}

// Тест вставки и проверки размера сета
TEST(MultisetTest, InsertAndSize) {
  s21::Multiset<int> myMultiset;
  myMultiset.insert(1);
  myMultiset.insert(2);
  myMultiset.insert(3);

  EXPECT_EQ(myMultiset.size(), 3u);
}

// Тест удаления элемента и проверки размера сета
TEST(MultisetTest, RemoveAndSize) {
  s21::Multiset<int> myMultiset = {1, 2, 3};

  myMultiset.erase(2);

  EXPECT_EQ(myMultiset.size(), 2u);
  EXPECT_EQ(myMultiset.contains(2), false);
}

TEST(MultisetTest, Search) {
  s21::Multiset<int> myMultiset = {1, 2, 3};
  EXPECT_TRUE(myMultiset.find(1));
  EXPECT_TRUE(myMultiset.find(2));
  EXPECT_TRUE(myMultiset.find(3));
  EXPECT_FALSE(myMultiset.find(4));
}

// Тест проверки на пустоту
TEST(MultisetTest, Empty) {
  s21::Multiset<int> myMultiset;
  EXPECT_TRUE(myMultiset.empty());

  myMultiset.insert(42);
  EXPECT_FALSE(myMultiset.empty());

  myMultiset.clear();
  EXPECT_TRUE(myMultiset.empty());
}

// Тест максимального размера
TEST(MultisetTest, MaxSize) {
  s21::Multiset<int> myMultiset;
  EXPECT_EQ(myMultiset.max_size(), std::numeric_limits<std::size_t>::max());
}

// Тест отчистки
TEST(MultisetTest, Clear) {
  s21::Multiset<int> myMultiset = {1, 2, 3};

  myMultiset.clear();
  EXPECT_TRUE(myMultiset.empty());
  EXPECT_EQ(myMultiset.size(), 0u);
}

// Тест метода проверки на содержание
TEST(MultisetTest, Contains) {
  s21::Multiset<int> myMultiset = {1, 2, 3};

  EXPECT_TRUE(myMultiset.contains(2));
  EXPECT_FALSE(myMultiset.contains(4));
}

// Тест методов итератора: конец/начало/итерации
TEST(MultisetTest, BeginEnd) {
  s21::Multiset<int> myMultiset = {1, 2, 3};

  auto it = myMultiset.begin();
  EXPECT_EQ(*it, 1);

  ++it;
  EXPECT_EQ(*it, 2);

  ++it;
  EXPECT_EQ(*it, 3);

  ++it;
  EXPECT_EQ(it, myMultiset.end());
}

// Тест для сравнения s21::Multiset и std::multiset
TEST(MultisetComparisonTest, SameElements) {
  // Создаем и наполняем наш сет
  s21::Multiset<int> myMultiset = {1, 2, 3};

  // Создаем и наполняем std::multiset
  std::multiset<int> stdMultiset = {1, 2, 3};

  // Сравниваем размеры
  EXPECT_EQ(myMultiset.size(), stdMultiset.size());

  // Сравниваем содержимое
  EXPECT_TRUE(
      std::equal(myMultiset.begin(), myMultiset.end(), stdMultiset.begin()));
}

TEST(MultisetComparisonTest, Insertion) {
  // Создаем наш сет
  s21::Multiset<int> myMultiset;

  // Вставляем элементы
  myMultiset.insert(1);
  myMultiset.insert(2);
  myMultiset.insert(3);

  // Создаем std::multiset и вставляем те же элементы
  std::multiset<int> stdMultiset;
  stdMultiset.insert(1);
  stdMultiset.insert(2);
  stdMultiset.insert(3);

  // Сравниваем размеры
  EXPECT_EQ(myMultiset.size(), stdMultiset.size());

  // Сравниваем содержимое
  EXPECT_TRUE(
      std::equal(myMultiset.begin(), myMultiset.end(), stdMultiset.begin()));
}

// Тест для сравнения метода contains у s21::Multiset и std::multiset
TEST(MultisetComparisonTest, Contains) {
  // Создаем и наполняем наш сет
  s21::Multiset<int> myMultiset = {1, 2, 3};

  // Создаем и наполняем std::multiset
  std::multiset<int> stdMultiset = {1, 2, 3};

  // Сравнение метода contains
  EXPECT_EQ(myMultiset.contains(2), stdMultiset.count(2) > 0);
}

// Тест для сравнения метода merge у s21::Multiset и std::multiset
TEST(MultisetComparisonTest, Merge) {
  // Создаем и наполняем наш сет
  s21::Multiset<int> myMultiset = {1, 2, 3};
  s21::Multiset<int> otherMultiset = {3, 4, 5};
  myMultiset.merge(otherMultiset);

  // Создаем и наполняем std::multiset
  std::multiset<int> stdMultiset = {1, 2, 3};
  std::multiset<int> otherStdMultiset = {3, 4, 5};
  stdMultiset.insert(otherStdMultiset.begin(), otherStdMultiset.end());

  // Сравнение размеров
  EXPECT_EQ(myMultiset.size(), stdMultiset.size());

  // Сравнение содержимого
  EXPECT_TRUE(
      std::equal(myMultiset.begin(), myMultiset.end(), stdMultiset.begin()));
}

// Тест для сравнения метода swap у s21::Multiset и std::multiset
TEST(MultisetComparisonTest, Swap) {
  // Создаем и наполняем наш сет
  s21::Multiset<int> myMultiset = {1, 2, 3};
  s21::Multiset<int> emptyMultiset;

  // Создаем и наполняем std::multiset
  std::multiset<int> stdMultiset = {1, 2, 3};
  std::multiset<int> emptyStdMultiset;

  // Сравнение метода swap
  myMultiset.swap(emptyMultiset);
  stdMultiset.swap(emptyStdMultiset);

  // Проверка, что оба сета после swap пусты
  EXPECT_TRUE(myMultiset.empty());
  EXPECT_FALSE(emptyMultiset.empty());
  EXPECT_TRUE(stdMultiset.empty());
  EXPECT_FALSE(emptyStdMultiset.empty());
}

// Тест для сравнения метода erase у s21::Multiset и std::multiset
TEST(MultisetComparisonTest, Erase) {
  // Создаем и наполняем наш сет
  s21::Multiset<int> myMultiset = {1, 2, 3};

  // Создаем и наполняем std::multiset
  std::multiset<int> stdMultiset = {1, 2, 3};

  // Сравнение метода erase
  myMultiset.erase(2);
  stdMultiset.erase(2);

  // Сравнение размеров
  EXPECT_EQ(myMultiset.size(), stdMultiset.size());

  // Сравнение содержимого
  EXPECT_TRUE(
      std::equal(myMultiset.begin(), myMultiset.end(), stdMultiset.begin()));
}

// Тест для сравнения метода insert у s21::Multiset и std::multiset
TEST(MultisetComparisonTest, Insert) {
  // Создаем и наполняем наш сет
  s21::Multiset<int> myMultiset = {1, 2, 3};

  // Создаем и наполняем std::multiset
  std::multiset<int> stdMultiset = {1, 2, 3};

  // Сравнение метода insert
  myMultiset.insert(4);
  stdMultiset.insert(4);

  // Сравнение размеров
  EXPECT_EQ(myMultiset.size(), stdMultiset.size());

  // Сравнение содержимого
  EXPECT_TRUE(
      std::equal(myMultiset.begin(), myMultiset.end(), stdMultiset.begin()));
}

// Тест для сравнения метода insert у s21::Multiset и std::multiset
TEST(MultisetComparisonTest2, Insert) {
  // Создаем и наполняем наш сет
  s21::Multiset<int> myMultiset = {1, 1, 1};

  // Создаем и наполняем std::multiset
  std::multiset<int> stdMultiset = {1, 1, 1};

  // Добавляем элементы в оба мультисета
  myMultiset.insert(1);
  stdMultiset.insert(1);

  // Сравнение размеров
  EXPECT_EQ(myMultiset.size(), stdMultiset.size());

  // Сравнение содержимого
  EXPECT_TRUE(
      std::equal(myMultiset.begin(), myMultiset.end(), stdMultiset.begin()));
}

// Тест для сравнения метода erase у s21::Multiset и std::multiset
TEST(MultisetComparisonTest1, Erase) {
  s21::Multiset<int> myMultiset = {1, 1, 3};
  std::multiset<int> stdMultiset = {1, 1, 3};
  myMultiset.erase(1);
  stdMultiset.erase(1);
  EXPECT_EQ(myMultiset.size(), stdMultiset.size());
  EXPECT_TRUE(
      std::equal(myMultiset.begin(), myMultiset.end(), stdMultiset.begin()));
}

TEST(MultisetComparisonTest2, Erase) {
  s21::Multiset<int> myMultiset = {1, 1, 3};
  std::multiset<int> stdMultiset = {1, 1, 3};
  myMultiset.erase(3);
  stdMultiset.erase(3);
  EXPECT_EQ(myMultiset.size(), stdMultiset.size());
  EXPECT_TRUE(
      std::equal(myMultiset.begin(), myMultiset.end(), stdMultiset.begin()));
}

TEST(MultisetTest, DefaultConstructor) {
  s21::Multiset<int> myMultiset;
  EXPECT_TRUE(myMultiset.empty());
  EXPECT_EQ(myMultiset.size(), 0u);
}

TEST(MultisetTest, InitializerListConstructor) {
  s21::Multiset<int> myMultiset = {1, 2, 3};
  EXPECT_FALSE(myMultiset.empty());
  EXPECT_EQ(myMultiset.size(), 3u);
}

TEST(MultisetTest, CopyConstructor) {
  s21::Multiset<int> myMultiset = {1, 2, 3};
  s21::Multiset<int> copiedMultiset(myMultiset);
  EXPECT_FALSE(copiedMultiset.empty());
  EXPECT_EQ(copiedMultiset.size(), 3u);
}

TEST(MultisetTest, MoveConstructor) {
  s21::Multiset<int> myMultiset = {1, 2, 3};
  s21::Multiset<int> movedMultiset(std::move(myMultiset));
  EXPECT_TRUE(myMultiset.empty());
  EXPECT_EQ(movedMultiset.size(), 3u);
}

TEST(MultisetTest, Destructor) {
  s21::Multiset<int>* myMultiset = new s21::Multiset<int>{1, 2, 3};
  delete myMultiset;
  // Check that the destructor doesn't cause any errors
  SUCCEED();
}

TEST(MultisetTest, MoveAssignmentOperator) {
  s21::Multiset<int> myMultiset = {1, 2, 3};
  s21::Multiset<int> anotherMultiset;
  anotherMultiset = std::move(myMultiset);
  EXPECT_TRUE(myMultiset.empty());
  EXPECT_EQ(anotherMultiset.size(), 3u);
}

TEST(MultisetTest, Empty2) {
  s21::Multiset<int> myMultiset;
  EXPECT_TRUE(myMultiset.empty());
  myMultiset.insert(42);
  EXPECT_FALSE(myMultiset.empty());
}

TEST(MultisetTest, Size) {
  s21::Multiset<int> myMultiset = {1, 2, 3};
  EXPECT_EQ(myMultiset.size(), 3u);
  myMultiset.erase(3);
  EXPECT_EQ(myMultiset.size(), 2u);
}

TEST(MultisetTest, MaxSize2) {
  s21::Multiset<int> myMultiset;
  EXPECT_LE(myMultiset.size(), myMultiset.max_size());
}

TEST(MultisetComparisonTest, EqualRange) {
  // Создаем и наполняем ваш мультисет
  s21::Multiset<int> myMultiset = {1, 2, 3, 3, 4};

  // Создаем и наполняем std::multiset
  std::multiset<int> stdMultiset = {1, 2, 3, 3, 4};

  // Проверяем equal_range
  auto myRange = myMultiset.equal_range(3);
  auto stdRange = stdMultiset.equal_range(3);

  // Сравнение размеров диапазонов
  EXPECT_EQ(std::distance(myRange.first, myRange.second),
            std::distance(stdRange.first, stdRange.second));

  // Сравнение содержимого
  EXPECT_TRUE(std::equal(myRange.first, myRange.second, stdRange.first));
}

TEST(MultisetComparisonTest, LowerBound) {
  // Создаем и наполняем ваш мультисет
  s21::Multiset<int> myMultiset = {1, 2, 3, 3, 4};

  // Создаем и наполняем std::multiset
  std::multiset<int> stdMultiset = {1, 2, 3, 3, 4};

  // Проверяем lower_bound
  auto myLowerBound = myMultiset.lower_bound(3);
  auto stdLowerBound = stdMultiset.lower_bound(3);

  // Сравнение значений lower_bound
  EXPECT_EQ(*myLowerBound, *stdLowerBound);
}

TEST(MultisetComparisonTest, UpperBound) {
  // Создаем и наполняем ваш мультисет
  s21::Multiset<int> myMultiset = {1, 2, 3, 3, 4};

  // Создаем и наполняем std::multiset
  std::multiset<int> stdMultiset = {1, 2, 3, 3, 4};

  // Проверяем upper_bound
  auto myUpperBound = myMultiset.upper_bound(3);
  auto stdUpperBound = stdMultiset.upper_bound(3);

  // Сравнение значений upper_bound
  EXPECT_EQ(*myUpperBound, *stdUpperBound);
}

// Тест для сравнения метода merge у s21::Multiset и std::multiset
TEST(MultisetComparisonTest2, Merge) {
  // Создаем и наполняем наш сет
  s21::Multiset<int> myMultiset = {1, 2, 3};
  s21::Multiset<int> otherMultiset = {3, 3, 5};
  myMultiset.merge(otherMultiset);

  // Создаем и наполняем std::multiset
  std::multiset<int> stdMultiset = {1, 2, 3};
  std::multiset<int> otherStdMultiset = {3, 3, 5};
  stdMultiset.insert(otherStdMultiset.begin(), otherStdMultiset.end());

  // Сравнение размеров
  EXPECT_EQ(myMultiset.size(), stdMultiset.size());

  // Сравнение содержимого
  EXPECT_TRUE(
      std::equal(myMultiset.begin(), myMultiset.end(), stdMultiset.begin()));
}
