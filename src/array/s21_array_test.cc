#include <gtest/gtest.h>

#include <array>

#include "../s21_containersplus.h"

// Тестирование метода size
TEST(Array, SizeArray) {
  s21::Array<int, 3> s21_array = {1, 2, 3};
  std::array<int, 3> std_array = {1, 2, 3};
  EXPECT_EQ(s21_array.size(), std_array.size());
}

// Тестирование оператора []
TEST(Array, FrontBackArray) {
  s21::Array<int, 3> s21_array = {1, 2, 3};
  std::array<int, 3> std_array = {1, 2, 3};
  EXPECT_EQ(s21_array.front(), std_array.front());
  EXPECT_EQ(s21_array.back(), std_array.back());
}

// Тестирование методов begin и end
TEST(Array, BeginEndArray) {
  s21::Array<int, 3> s21_array = {1, 2, 3};
  std::array<int, 3> std_array = {1, 2, 3};
  EXPECT_EQ(*s21_array.begin(), *std_array.begin());
  EXPECT_EQ(*(s21_array.end() - 1), *(std_array.end() - 1));
}

// Тестирование метода data
TEST(Array, DataArray) {
  s21::Array<int, 3> s21_array = {1, 2, 3};
  std::array<int, 3> std_array = {1, 2, 3};
  EXPECT_EQ(*s21_array.data(), *std_array.data());
}

// Тестирование методов empty
TEST(Array, EmptyArray) {
  s21::Array<int, 3> s21_array = {1, 2, 3};
  std::array<int, 3> std_array = {1, 2, 3};
  EXPECT_EQ(s21_array.empty(), std_array.empty());
}

TEST(Array, EmptyArraySecond) {
  s21::Array<int, 3> s21_array;
  std::array<int, 3> std_array;
  EXPECT_EQ(s21_array.empty(), std_array.empty());
}

// Тестирование методов max_size
TEST(Array, MaxSizeArray) {
  s21::Array<int, 1> s21_array;
  std::array<int, 1> std_array;
  EXPECT_TRUE(s21_array.max_size());
  EXPECT_TRUE(std_array.max_size());
}

TEST(Array, MaxSizeArraySecond) {
  s21::Array<int, 10> s21_array = {1, 3, 8, 5, 6, 3, 6, 3, 2, 10};
  std::array<int, 10> std_array = {1, 3, 8, 5, 6, 3, 6, 3, 2, 10};
  EXPECT_TRUE(s21_array.max_size());
  EXPECT_TRUE(std_array.max_size());
}

// Тестирование методов swap и fill
TEST(Array, SwapArray) {
  s21::Array<int, 3> s21_array1 = {1, 2, 3};
  s21::Array<int, 3> s21_array2 = {4, 5, 6};
  std::array<int, 3> std_array1 = {1, 2, 3};
  std::array<int, 3> std_array2 = {4, 5, 6};

  s21_array1.swap(s21_array2);
  std_array1.swap(std_array2);
  EXPECT_EQ(s21_array1[0], std_array1[0]);
  EXPECT_EQ(s21_array2[0], std_array2[0]);
  EXPECT_EQ(s21_array1[1], std_array1[1]);
  EXPECT_EQ(s21_array2[1], std_array2[1]);
  EXPECT_EQ(s21_array1[2], std_array1[2]);
  EXPECT_EQ(s21_array2[2], std_array2[2]);
}

// Тестирование методов fill
TEST(Array, FillArray) {
  s21::Array<int, 3> s21_array1 = {1, 2, 3};
  std::array<int, 3> std_array1 = {4, 5, 6};
  s21_array1.fill(42);
  std_array1.fill(42);
  EXPECT_EQ(s21_array1[0], std_array1[0]);
  EXPECT_EQ(s21_array1[1], std_array1[1]);
  EXPECT_EQ(s21_array1[2], std_array1[2]);
  EXPECT_EQ(s21_array1[2], std_array1[2]);
}

TEST(Array, IteratorArray) {
  s21::Array<int, 3> s21_array1 = {1, 2, 3};
  std::array<int, 3> std_array1 = {1, 2, 3};
  auto it = s21_array1.begin();
  auto iter = std_array1.begin();
  EXPECT_EQ(*it, *iter);
}

TEST(Array, IteratorArraySecond) {
  s21::Array<int, 3> s21_array1 = {1, 2, 3};
  std::array<int, 3> std_array1 = {1, 2, 3};
  auto it = s21_array1.begin();
  it++;
  ++it;
  auto iter = std_array1.begin();
  iter++;
  ++iter;
  EXPECT_EQ(*it, *iter);
}

TEST(Array, IteratorArrayThird) {
  s21::Array<int, 3> s21_array1 = {1, 2, 3};
  std::array<int, 3> std_array1 = {1, 2, 3};
  auto it = s21_array1.end();
  --it;
  auto iter = std_array1.end();
  --iter;
  EXPECT_EQ(*it, *iter);
}

TEST(Array, IteratorArrayFourth) {
  s21::Array<int, 3> s21_array1 = {1, 2, 3};
  std::array<int, 3> std_array1 = {1, 2, 3};
  auto it = s21_array1.end();
  --it;
  --it;
  auto iter = std_array1.end();
  --iter;
  --iter;
  EXPECT_EQ(*it, *iter);
}

TEST(Array, Operator) {
  s21::Array<int, 5> s21_array1 = {1, 2, 3, 4, 5};
  std::array<int, 5> std_array1 = {1, 2, 3, 4, 5};
  EXPECT_EQ(s21_array1[0], std_array1[0]);
  EXPECT_EQ(s21_array1[1], std_array1[1]);
  EXPECT_EQ(s21_array1[2], std_array1[2]);
  EXPECT_EQ(s21_array1[3], std_array1[3]);
  EXPECT_EQ(s21_array1[4], std_array1[4]);
}

TEST(Array, OperatorSecond) {
  s21::Array<int, 3> s21_array1 = {1, 2, 3};
  EXPECT_ANY_THROW(s21_array1.at(20));
}

TEST(Array, OperatorThird) {
  s21::Array<int, 3> s21_array = {1, 2, 3};
  s21::Array<int, 3> s21_array2 = s21_array;
  EXPECT_EQ(s21_array[0], s21_array2[0]);
  EXPECT_EQ(s21_array[1], s21_array2[1]);
  EXPECT_EQ(s21_array[2], s21_array2[2]);
}

TEST(Array, OperatorFourth) {
  s21::Array<int, 3> s21_array = {1, 2, 3};
  s21::Array<int, 3> s21_array2 = std::move(s21_array);
  EXPECT_EQ(s21_array[0], s21_array2[0]);
  EXPECT_EQ(s21_array[1], s21_array2[1]);
  EXPECT_EQ(s21_array[2], s21_array2[2]);
}

TEST(Array, Constructor) {
  s21::Array<int, 3> s21_array1;
  EXPECT_ANY_THROW(s21_array1.at(20));
}

TEST(Array, ConstructorSecond) {
  s21::Array<int, 3> s21_array = {1, 2, 3};
  s21::Array<int, 3> s21_array2(s21_array);
  std::array<int, 3> std_array = {1, 2, 3};
  std::array<int, 3> std_array2(std_array);
  EXPECT_EQ(s21_array[0], std_array[0]);
  EXPECT_EQ(s21_array[1], std_array[1]);
  EXPECT_EQ(s21_array[2], std_array[2]);
  EXPECT_EQ(s21_array2[0], std_array2[0]);
  EXPECT_EQ(s21_array2[1], std_array2[1]);
  EXPECT_EQ(s21_array2[2], std_array2[2]);
}

TEST(Array, ConstructorThird) {
  s21::Array<int, 3> s21_array = {1, 2, 3};
  s21::Array<int, 3> s21_array2(std::move(s21_array));
  std::array<int, 3> std_array = {1, 2, 3};
  std::array<int, 3> std_array2(std::move(std_array));
  EXPECT_EQ(s21_array[0], std_array[0]);
  EXPECT_EQ(s21_array[1], std_array[1]);
  EXPECT_EQ(s21_array[2], std_array[2]);
  EXPECT_EQ(s21_array2[0], std_array2[0]);
  EXPECT_EQ(s21_array2[1], std_array2[1]);
  EXPECT_EQ(s21_array2[2], std_array2[2]);
}
