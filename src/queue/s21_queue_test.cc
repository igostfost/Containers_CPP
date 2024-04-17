#include <gtest/gtest.h>

#include "../s21_containers.h"

// Tests case for default constructor and empty method
TEST(QueueTest, DefaultConstructorAndEmptyInt) {
  s21::Queue<int> intQueue;
  EXPECT_TRUE(intQueue.empty());
  EXPECT_EQ(intQueue.size(), 0u);
}

TEST(QueueTest, DefaultConstructorAndEmptyFloat) {
  s21::Queue<float> floatQueue;
  EXPECT_TRUE(floatQueue.empty());
  EXPECT_EQ(floatQueue.size(), 0u);
}

TEST(QueueTest, DefaultConstructorAndEmptyChar) {
  s21::Queue<char> charQueue;
  EXPECT_TRUE(charQueue.empty());
  EXPECT_EQ(charQueue.size(), 0u);
}

// Test case for initializer list constructor and size method
TEST(QueueTest, InitializerListConstructorAndSizeInt) {
  s21::Queue<int> intQueue = {1, 2, 3};
  EXPECT_FALSE(intQueue.empty());
  EXPECT_EQ(intQueue.size(), 3u);
}

TEST(QueueTest, InitializerListConstructorAndSizeFloat) {
  s21::Queue<float> floatQueue = {1.0, 2.0, 3.0};
  EXPECT_FALSE(floatQueue.empty());
  EXPECT_EQ(floatQueue.size(), 3u);
}

TEST(QueueTest, InitializerListConstructorAndSizeChar) {
  s21::Queue<char> charQueue = {'1', '2', '3'};
  EXPECT_FALSE(charQueue.empty());
  EXPECT_EQ(charQueue.size(), 3u);
}

TEST(QueueTest, LargeInitializerList) {
  s21::Queue<int> largeQueue = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_FALSE(largeQueue.empty());
  EXPECT_EQ(largeQueue.size(), 10u);
}

TEST(QueueTest, SingleElementInitializerList) {
  s21::Queue<int> singleElementQueue = {42};
  EXPECT_FALSE(singleElementQueue.empty());
  EXPECT_EQ(singleElementQueue.size(), 1u);
  EXPECT_EQ(singleElementQueue.front(), 42);
  EXPECT_EQ(singleElementQueue.back(), 42);
}

TEST(QueueTest, EmptyInitializerList) {
  s21::Queue<int> emptyQueue = {};
  EXPECT_TRUE(emptyQueue.empty());
  EXPECT_EQ(emptyQueue.size(), 0u);
}

// Test case for copy constructor
TEST(QueueTest, CopyConstructorInt) {
  s21::Queue<int> original = {1, 2, 3};
  s21::Queue<int> copied(original);

  EXPECT_FALSE(copied.empty());
  EXPECT_EQ(copied.size(), original.size());

  for (size_t i = 0; i < original.size(); ++i) {
    EXPECT_EQ(original.front(), copied.front());
    original.pop();
    copied.pop();
  }
}

TEST(QueueTest, CopyConstructorFloat) {
  s21::Queue<float> original = {1.0, 2.0, 3.0};
  s21::Queue<float> copied(original);

  EXPECT_FALSE(copied.empty());
  EXPECT_EQ(copied.size(), original.size());

  for (size_t i = 0; i < original.size(); ++i) {
    EXPECT_FLOAT_EQ(original.front(), copied.front());
    original.pop();
    copied.pop();
  }
}

TEST(QueueTest, CopyConstructorChar) {
  s21::Queue<char> original = {'1', '2', '3'};
  s21::Queue<char> copied(original);

  EXPECT_FALSE(copied.empty());
  EXPECT_EQ(copied.size(), original.size());

  for (size_t i = 0; i < original.size(); ++i) {
    EXPECT_EQ(original.front(), copied.front());
    original.pop();
    copied.pop();
  }
}

// Test case for move constructor
TEST(QueueTest, MoveConstructorInt) {
  s21::Queue<int> original = {1, 2, 3};
  s21::Queue<int> moved(std::move(original));

  EXPECT_FALSE(moved.empty());
  EXPECT_EQ(moved.size(), 3u);

  EXPECT_TRUE(original.empty());
  EXPECT_EQ(original.size(), 0u);
}

TEST(QueueTest, MoveConstructorFloat) {
  s21::Queue<float> original = {1.0, 2.0, 3.0};
  s21::Queue<float> moved(std::move(original));

  EXPECT_FALSE(moved.empty());
  EXPECT_EQ(moved.size(), 3u);

  EXPECT_TRUE(original.empty());
  EXPECT_EQ(original.size(), 0u);
}

TEST(QueueTest, MoveConstructorChar) {
  s21::Queue<char> original = {'1', '2', '3'};
  s21::Queue<char> moved(std::move(original));

  EXPECT_FALSE(moved.empty());
  EXPECT_EQ(moved.size(), 3u);

  EXPECT_TRUE(original.empty());
  EXPECT_EQ(original.size(), 0u);
}

// Test case for move assignment operator =
TEST(QueueTest, MoveAssignmentInt) {
  s21::Queue<int> original = {1, 2, 3};
  s21::Queue<int> assigned;
  assigned = std::move(original);

  EXPECT_TRUE(original.empty());
  EXPECT_EQ(original.size(), 0u);

  EXPECT_FALSE(assigned.empty());
  EXPECT_EQ(assigned.size(), 3u);
  EXPECT_EQ(assigned.front(), 1);
  EXPECT_EQ(assigned.back(), 3);
}

TEST(QueueTest, MoveAssignmentFloat) {
  s21::Queue<float> original = {1.1f, 2.2f, 3.3f};
  s21::Queue<float> assigned;
  assigned = std::move(original);

  EXPECT_TRUE(original.empty());
  EXPECT_EQ(original.size(), 0u);

  EXPECT_FALSE(assigned.empty());
  EXPECT_EQ(assigned.size(), 3u);
  EXPECT_FLOAT_EQ(assigned.front(), 1.1f);
  EXPECT_FLOAT_EQ(assigned.back(), 3.3f);
}

TEST(QueueTest, MoveAssignmentChar) {
  s21::Queue<char> original = {'a', 'b', 'c'};
  s21::Queue<char> assigned;
  assigned = std::move(original);

  EXPECT_TRUE(original.empty());
  EXPECT_EQ(original.size(), 0u);

  EXPECT_FALSE(assigned.empty());
  EXPECT_EQ(assigned.size(), 3u);
  EXPECT_EQ(assigned.front(), 'a');
  EXPECT_EQ(assigned.back(), 'c');
}

// Test case for push method
TEST(QueueTest, PushInt) {
  s21::Queue<int> intQueue;
  intQueue.push(21);
  EXPECT_FALSE(intQueue.empty());
  EXPECT_EQ(intQueue.size(), 1u);
  EXPECT_EQ(intQueue.front(), 21);
  EXPECT_EQ(intQueue.back(), 21);
}

TEST(QueueTest, PushFloat) {
  s21::Queue<float> floatQueue;
  floatQueue.push(21.1f);
  EXPECT_FALSE(floatQueue.empty());
  EXPECT_EQ(floatQueue.size(), 1u);
  EXPECT_FLOAT_EQ(floatQueue.front(), 21.1f);
  EXPECT_FLOAT_EQ(floatQueue.back(), 21.1f);
}

TEST(QueueTest, PushChar) {
  s21::Queue<char> charQueue;
  charQueue.push('1');
  EXPECT_FALSE(charQueue.empty());
  EXPECT_EQ(charQueue.size(), 1u);
  EXPECT_EQ(charQueue.front(), '1');
  EXPECT_EQ(charQueue.back(), '1');
}

// Test case for pop method
TEST(QueueTest, PopInt) {
  s21::Queue<int> intQueue = {1, 2, 3};
  intQueue.pop();
  EXPECT_FALSE(intQueue.empty());
  EXPECT_EQ(intQueue.size(), 2u);
  EXPECT_EQ(intQueue.front(), 2);
  EXPECT_EQ(intQueue.back(), 3);
}

TEST(QueueTest, PopFloat) {
  s21::Queue<float> floatQueue = {1.0, 2.0, 3.0};
  floatQueue.pop();
  EXPECT_FALSE(floatQueue.empty());
  EXPECT_EQ(floatQueue.size(), 2u);
  EXPECT_FLOAT_EQ(floatQueue.front(), 2.0f);
  EXPECT_FLOAT_EQ(floatQueue.back(), 3.0f);
}

TEST(QueueTest, PopChar) {
  s21::Queue<int> charQueue = {'1', '2', '3'};
  charQueue.pop();
  EXPECT_FALSE(charQueue.empty());
  EXPECT_EQ(charQueue.size(), 2u);
  EXPECT_EQ(charQueue.front(), '2');
  EXPECT_EQ(charQueue.back(), '3');
}

// Test case for swap method
TEST(QueueTest, SwapInt) {
  s21::Queue<int> queue1 = {1, 2, 3};
  s21::Queue<int> queue2 = {4, 5, 6};

  queue1.swap(queue2);

  EXPECT_EQ(queue1.size(), 3u);
  EXPECT_EQ(queue2.size(), 3u);

  for (int i = 0; i < 3; ++i) {
    EXPECT_EQ(queue1.front(), i + 4);
    EXPECT_EQ(queue2.front(), i + 1);
    queue1.pop();
    queue2.pop();
  }
}

TEST(QueueTest, SwapFloat) {
  s21::Queue<float> queue1 = {1.0, 2.0, 3.0};
  s21::Queue<float> queue2 = {4.0, 5.0, 6.0};

  queue1.swap(queue2);

  EXPECT_EQ(queue1.size(), 3u);
  EXPECT_EQ(queue2.size(), 3u);

  for (float i = 0.0; i < 3.0; ++i) {
    EXPECT_FLOAT_EQ(queue1.front(), i + 4.0);
    EXPECT_FLOAT_EQ(queue2.front(), i + 1.0);
    queue1.pop();
    queue2.pop();
  }
}

TEST(QueueTest, SwapChar) {
  s21::Queue<char> queue1 = {'1', '2', '3'};
  s21::Queue<char> queue2 = {'4', '5', '6'};

  queue1.swap(queue2);

  EXPECT_EQ(queue1.size(), 3u);
  EXPECT_EQ(queue2.size(), 3u);

  EXPECT_EQ(queue1.front(), '4');
  EXPECT_EQ(queue2.front(), '1');
  EXPECT_EQ(queue1.back(), '6');
  EXPECT_EQ(queue2.back(), '3');
}
