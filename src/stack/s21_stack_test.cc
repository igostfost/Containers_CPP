#include <gtest/gtest.h>

#include <stack>

#include "../s21_containers.h"

TEST(TestConstructor, ConstructorDefault) {
  Stack<size_t> s;
  std::stack<size_t> o;
  ASSERT_EQ(s.size(), o.size());
}

TEST(TestConstructor, ConstructorInit) {
  Stack<size_t> s = {1, 2, 3, 4, 5};
  ASSERT_EQ(s.top(), 5u);
  ASSERT_EQ(s.size(), 5u);
}

TEST(TestConstructor, ConstructorCopy) {
  Stack<size_t> s = {1, 2, 3, 4, 5};
  Stack<size_t> a(s);
  ASSERT_EQ(s.top(), a.top());
  ASSERT_EQ(s.size(), a.size());
}

TEST(TestConstructor, ConstructorMove) {
  std::stack<size_t> s1 = std::stack<size_t>({1, 2, 3, 4, 5});
  std::stack<size_t> a(std::move(s1));
  Stack<size_t> s2 = {1, 2, 3, 4, 5};
  Stack<size_t> b(std::move(s2));
  ASSERT_EQ(a.top(), b.top());
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestConstructor, OperatorEqual) {
  Stack<size_t> a1 = {1, 2, 3, 4, 5};
  Stack<size_t> b1 = {1, 2, 3};
  std::stack<size_t> a2 = std::stack<size_t>({1, 2, 3, 4, 5});
  std::stack<size_t> b2 = std::stack<size_t>({1, 2, 3});
  b1 = std::move(a1);
  b2 = std::move(a2);
  ASSERT_EQ(b1.top(), b2.top());
  ASSERT_EQ(b1.size(), b2.size());
  ASSERT_EQ(a1.size(), a2.size());
}

TEST(TestConstructor, OperatorEqualSecond) {
  Stack<size_t> a1 = {1, 2, 3};
  Stack<size_t> b1 = {1, 2, 3, 4, 5};
  std::stack<size_t> a2 = std::stack<size_t>({1, 2, 3});
  std::stack<size_t> b2 = std::stack<size_t>({1, 2, 3, 4, 5});
  b1 = std::move(a1);
  b2 = std::move(a2);
  ASSERT_EQ(b1.top(), b2.top());
  ASSERT_EQ(b1.size(), b2.size());
  ASSERT_EQ(a1.size(), a2.size());
}

TEST(TestConstructor, OperatorEqualThird) {
  Stack<size_t> a1 = {1, 2, 3, 4, 5};
  Stack<size_t> b1 = {2, 5};
  a1 = b1;
  std::stack<size_t> a2 = std::stack<size_t>({1, 2, 3, 4, 5});
  std::stack<size_t> b2 = std::stack<size_t>({2, 5});
  a2 = b2;
  ASSERT_EQ(a1.top(), a2.top());
  ASSERT_EQ(a1.size(), a2.size());
}

TEST(TestConstructor, OperatorEqualFourth) {
  Stack<size_t> a1 = {2, 5};
  Stack<size_t> b1 = {1, 2, 3, 4, 5};
  a1 = b1;
  std::stack<size_t> a2 = std::stack<size_t>({2, 5});
  std::stack<size_t> b2 = std::stack<size_t>({1, 2, 3, 4, 5});
  a2 = b2;
  ASSERT_EQ(a1.top(), a2.top());
  ASSERT_EQ(a1.size(), a2.size());
}

TEST(TestConstructor, Push) {
  Stack<size_t> a = {1, 2, 3, 4, 5};
  a.push(10);
  std::stack<size_t> b = std::stack<size_t>({1, 2, 3, 4, 5});
  b.push(10);
  ASSERT_EQ(a.top(), b.top());
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestConstructor, Pop) {
  Stack<size_t> a = {1, 2, 3, 4, 5};
  a.pop();
  std::stack<size_t> b = std::stack<size_t>({1, 2, 3, 4, 5});
  b.pop();
  ASSERT_EQ(a.top(), b.top());
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestConstructor, Empty) {
  Stack<size_t> a;
  std::stack<size_t> b;
  ASSERT_EQ(a.empty(), b.empty());
  a = {1, 2, 3, 4, 5};
  b = std::stack<size_t>({1, 2, 3, 4, 5});
  ASSERT_EQ(a.empty(), b.empty());
}

TEST(TestConstructor, Swap) {
  Stack<size_t> a1 = {1, 2, 3};
  Stack<size_t> b1 = {1, 2, 3, 4, 5};
  std::stack<size_t> a2 = std::stack<size_t>({1, 2, 3});
  std::stack<size_t> b2 = std::stack<size_t>({1, 2, 3, 4, 5});
  a1.swap(b1);
  a2.swap(b2);
  ASSERT_EQ(a1.size(), a2.size());
  ASSERT_EQ(b1.size(), b2.size());
  ASSERT_EQ(a1.top(), a2.top());
  ASSERT_EQ(b1.top(), b2.top());
}

TEST(TestConstructor, Size) {
  Stack<size_t> a = {1, 2, 3, 4, 5};
  std::stack<size_t> b = std::stack<size_t>({1, 2, 3, 4, 5});
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestConstructor, Top) {
  Stack<size_t> a = {1, 2, 3, 4, 5};
  std::stack<size_t> b = std::stack<size_t>({1, 2, 3, 4, 5});
  ASSERT_EQ(a.top(), b.top());
}
