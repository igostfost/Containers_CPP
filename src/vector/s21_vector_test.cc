#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "../s21_containers.h"

TEST(TestVectorConstructor, ConstructorFirst) {
  s21::Vector<int> V = {1, 2, 3, 4, 5};
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
}

TEST(TestVectorConstructor, ConstructorSecond) {
  s21::Vector<int> V;
  std::vector<int> V2;
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.capacity(), V.capacity());
}

TEST(TestVectorConstructor, ConstructorThird) {
  s21::Vector<int> V = {1, 2, 3, 4, 5};
  s21::Vector<int> V3(V);
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  std::vector<int> V4(V2);
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(V3.capacity(), V4.capacity());
  ASSERT_EQ(V3[0], V4[0]);
  ASSERT_EQ(V3[1], V4[1]);
  ASSERT_EQ(V3[2], V4[2]);
  ASSERT_EQ(V3[3], V4[3]);
  ASSERT_EQ(V3[4], V4[4]);
}

TEST(TestVectorConstructor, ConstructorFourth) {
  s21::Vector<int> V = {1, 2, 3, 4, 5};
  s21::Vector<int> V3(std::move(V));
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  std::vector<int> V4(std::move(V2));
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(V3.capacity(), V4.capacity());
  ASSERT_EQ(V3[0], V4[0]);
  ASSERT_EQ(V3[1], V4[1]);
  ASSERT_EQ(V3[2], V4[2]);
  ASSERT_EQ(V3[3], V4[3]);
  ASSERT_EQ(V3[4], V4[4]);
}

TEST(TestVectorConstructor, ConstructorSixth) {
  s21::Vector<int> V(5);
  std::vector<int> V2(5);
  ASSERT_EQ(V.size(), V2.size());
  ASSERT_EQ(V.capacity(), V2.capacity());
}

TEST(TestVectorConstructor, ConstructorSeventh) {
  s21::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  s21::Vector<std::string> V3(std::move(V));
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  ;
  std::vector<std::string> V4(std::move(V2));
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(V3.capacity(), V4.capacity());
  ASSERT_EQ(V3[0], V4[0]);
  ASSERT_EQ(V3[1], V4[1]);
  ASSERT_EQ(V3[2], V4[2]);
  ASSERT_EQ(V3[3], V4[3]);
  ASSERT_EQ(V3[4], V4[4]);
}

TEST(TestVectorConstructor, ConstructorEighth) {
  s21::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  s21::Vector<std::string> V3(V);
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  ;
  std::vector<std::string> V4(V2);
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(V3.capacity(), V4.capacity());
  ASSERT_EQ(V3[0], V4[0]);
  ASSERT_EQ(V3[1], V4[1]);
  ASSERT_EQ(V3[2], V4[2]);
  ASSERT_EQ(V3[3], V4[3]);
  ASSERT_EQ(V3[4], V4[4]);
}

TEST(TestVectorConstructor, ConstructorNinth) {
  s21::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  s21::Vector<std::string> V3(std::move(V));
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  ;
  std::vector<std::string> V4(std::move(V2));
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(V3.capacity(), V4.capacity());
  ASSERT_EQ(V3[0], V4[0]);
  ASSERT_EQ(V3[1], V4[1]);
  ASSERT_EQ(V3[2], V4[2]);
  ASSERT_EQ(V3[3], V4[3]);
  ASSERT_EQ(V3[4], V4[4]);
}

TEST(TestVectorConstructor, ConstructorTenth) {
  s21::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  ;
  ASSERT_EQ(V.size(), V2.size());
  ASSERT_EQ(V.capacity(), V2.capacity());
  ASSERT_EQ(V[0], V2[0]);
  ASSERT_EQ(V[1], V2[1]);
  ASSERT_EQ(V[2], V2[2]);
  ASSERT_EQ(V[3], V2[3]);
  ASSERT_EQ(V[4], V2[4]);
}

TEST(TestVectorInsert, InsertFirst) {
  s21::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.begin();
  it++;
  it++;
  V.insert(it, 200);
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.begin();
  iter++;
  iter++;
  V2.insert(iter, 200);
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
}

TEST(TestVectorInsert, InsertSecond) {
  s21::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.end();
  it--;
  V.insert(it, 200);
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.end();
  iter--;
  V2.insert(iter, 200);
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
}

TEST(TestVectorInsert, InsertThird) {
  s21::Vector<int> V;
  V.push_back(2);
  V.push_back(1);
  V.push_back(3);
  V.push_back(4);
  auto it = V.begin();
  it++;
  V.insert(it, 200);
  std::vector<int> V2;
  V2.push_back(2);
  V2.push_back(1);
  V2.push_back(3);
  V2.push_back(4);
  auto iter = V2.begin();
  iter++;
  V2.insert(iter, 200);
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
}

TEST(TestVectorInsert, InsertFourth) {
  s21::Vector<int> V;
  V.push_back(2);
  V.push_back(3);
  V.push_back(4);
  V.push_back(5);
  V.push_back(8);
  V.push_back(4);
  auto it = V.begin();
  V.insert(it, 200);
  std::vector<int> V2;
  V2.push_back(2);
  V2.push_back(3);
  V2.push_back(4);
  V2.push_back(5);
  V2.push_back(8);
  V2.push_back(4);
  auto iter = V2.begin();
  V2.insert(iter, 200);
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
  ASSERT_EQ(V2.at(5), V.at(5));
  ASSERT_EQ(V2.at(6), V.at(6));
}

TEST(TestVectorInsert, InsertFifth) {
  s21::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.begin();
  for (size_t j = 0; j < V.size(); ++j) {
    it++;
  }
  V.insert(it, 200);
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.begin();
  for (size_t j = 0; j < V2.size(); ++j) {
    iter++;
  }
  V2.insert(iter, 200);
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
}

TEST(TestVectorInsert, InsertSixth) {
  s21::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  auto it = V.begin();
  for (size_t j = 0; j < V.size(); ++j) {
    it++;
  }
  V.insert(it, "e");
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  auto iter = V2.begin();
  for (size_t j = 0; j < V2.size(); ++j) {
    iter++;
  }
  V2.insert(iter, "e");
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
}

TEST(TestVectorInsert, InsertSeventh) {
  s21::Vector<char> V = {'a', 'b', 'c', 'd', 'f'};
  auto it = V.end();
  it--;
  V.insert(it, 'e');
  std::vector<char> V2 = {'a', 'b', 'c', 'd', 'f'};
  auto iter = V2.end();
  iter--;
  V2.insert(iter, 'e');
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
}

TEST(TestVectorShrinkToFit, ShrinkToFitFirst) {
  s21::Vector<int> V;
  V.resize(100);
  V.shrink_to_fit();
  std::vector<int> V2;
  V2.resize(100);
  V2.shrink_to_fit();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
}

TEST(TestVectorShrinkToFit, ShrinkToFitSecond) {
  s21::Vector<int> V;
  V.resize(100);
  V.resize(50);
  V.shrink_to_fit();
  std::vector<int> V2;
  V2.resize(100);
  V2.resize(50);
  V2.shrink_to_fit();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
}

TEST(TestVectorShrinkToFit, ShrinkToFitThird) {
  s21::Vector<int> V;
  V.resize(0);
  V.resize(100);
  V.resize(50);
  V.shrink_to_fit();
  V.shrink_to_fit();
  std::vector<int> V2;
  V2.resize(0);
  V2.resize(100);
  V2.resize(50);
  V2.shrink_to_fit();
  V2.shrink_to_fit();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
}

TEST(TestVectorPushBack, PushBackFirst) {
  s21::Vector<int> V = {1, 2, 3, 4, 5};
  V.push_back(6);
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  V2.push_back(6);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
  ASSERT_EQ(V2.at(5), V.at(5));
}

TEST(TestVectorPushBack, PushBackSecond) {
  s21::Vector<int> V;
  V.push_back(6);
  std::vector<int> V2;
  V2.push_back(6);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
}

TEST(TestVectorPushBack, PushBackThird) {
  s21::Vector<int> V;
  V.push_back(6);
  V.push_back(5);
  V.push_back(4);
  V.push_back(3);
  std::vector<int> V2;
  V2.push_back(6);
  V2.push_back(5);
  V2.push_back(4);
  V2.push_back(3);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
}

TEST(TestVectorPushBack, PushBackFourth) {
  s21::Vector<char> V;
  V.push_back('a');
  V.push_back('b');
  V.push_back('c');
  V.push_back('d');
  std::vector<char> V2;
  V2.push_back('a');
  V2.push_back('b');
  V2.push_back('c');
  V2.push_back('d');
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
}

TEST(TestVectorPushBack, PushBackFifth) {
  s21::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  V.push_back("e");
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  V2.push_back("e");
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
}

TEST(TestVectorPopBack, PopBackFirst) {
  s21::Vector<int> V = {1, 2, 3, 4, 5, 89};
  V.pop_back();
  std::vector<int> V2 = {1, 2, 3, 4, 5, 89};
  V2.pop_back();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
}

TEST(TestVectorPopBack, PopBackSecond) {
  s21::Vector<int> V = {1, 2, 3, 4};
  V.pop_back();
  std::vector<int> V2 = {1, 2, 3, 4};
  V2.pop_back();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
}

TEST(TestVectorPopBack, PopBackThird) {
  s21::Vector<int> V = {1, 2, 3, 4, 5};
  V.pop_back();
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  V2.pop_back();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
}

TEST(TestVectorPopBack, PopBackFourth) {
  s21::Vector<int> V;
  V.push_back(6);
  V.push_back(5);
  V.push_back(4);
  V.push_back(3);
  std::vector<int> V2;
  V2.push_back(6);
  V2.push_back(5);
  V2.push_back(4);
  V2.push_back(3);

  V.pop_back();
  V2.pop_back();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
}

TEST(TestVectorPopBack, PopBackFifth) {
  s21::Vector<int> V;
  std::vector<int> V2;
  V.pop_back();
  V2.pop_back();
  ASSERT_EQ(V2.capacity(), V.capacity());
}

TEST(TestVectorPopBack, PopBackSixth) {
  s21::Vector<int> V = {1};
  std::vector<int> V2 = {1};
  V.pop_back();
  V2.pop_back();
  ASSERT_EQ(V2.capacity(), V.capacity());
}

TEST(TestVectorPopBack, PopBackSeveth) {
  s21::Vector<char> V;
  V.push_back('a');
  V.push_back('b');
  V.push_back('c');
  V.push_back('d');
  std::vector<char> V2;
  V2.push_back('a');
  V2.push_back('b');
  V2.push_back('c');
  V2.push_back('d');
  V.pop_back();
  V2.pop_back();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
}

TEST(TestVectorPopBack, PopBackEighth) {
  s21::Vector<char> V = {'a', 'b', 'c', 'd', 'f'};
  std::vector<char> V2 = {'a', 'b', 'c', 'd', 'f'};
  V.pop_back();
  V2.pop_back();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
}

TEST(TestVectorClear, ClearFirst) {
  s21::Vector<int> V = {1, 2, 3, 4, 5};
  V.clear();
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  V2.clear();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
}

TEST(TestVectorClear, ClearSecond) {
  s21::Vector<int> V = {4848, 344, 4565, 899, 22, -4505};
  V.clear();
  std::vector<int> V2 = {4848, 344, 4565, 899, 22, -4505};
  V2.clear();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
}

TEST(TestVectorClear, ClearThird) {
  s21::Vector<int> V;
  V.clear();
  std::vector<int> V2;
  V2.clear();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
}

TEST(TestVectorErase, EraseFirst) {
  s21::Vector<int> V = {1};
  V.erase(V.begin());
  std::vector<int> V2 = {1};
  V2.erase(V2.begin());
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
}

TEST(TestVectorErase, EraseSecond) {
  s21::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.end();
  it--;
  it--;
  it--;
  V.erase(it);
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.end();
  iter--;
  iter--;
  iter--;
  V2.erase(iter);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
}

TEST(TestVectorErase, EraseThird) {
  s21::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.end();
  it--;
  V.erase(it);
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.end();
  iter--;
  V2.erase(iter);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
}

TEST(TestVectorErase, EraseFourth) {
  s21::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.end();
  it--;
  it--;
  V.erase(it);
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.end();
  iter--;
  iter--;
  V2.erase(iter);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
}

TEST(TestVectorErase, EraseSixth) {
  s21::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  V.erase(V.begin());
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  V2.erase(V2.begin());
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
}

TEST(TestVectorErase, EraseSeventh) {
  s21::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  auto it = V.erase(V.begin());
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  auto iter = V2.erase(V2.begin());
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(*iter, *it);
}

TEST(TestVectorFront, Front) {
  s21::Vector<int> V = {1, 2, 3};
  auto result_1 = V.front();
  std::vector<int> V2 = {1, 2, 3};
  auto result_2 = V2.front();
  ASSERT_EQ(result_1, result_2);
}

TEST(TestVectorBack, Back) {
  s21::Vector<int> V = {1, 2, 3};
  auto result_1 = V.back();
  std::vector<int> V2 = {1, 2, 3};
  auto result_2 = V2.back();
  ASSERT_EQ(result_1, result_2);
}

TEST(TestVectorData, DataFirst) {
  s21::Vector<int> V = {1, 2, 3};
  auto result_1 = V.data();
  std::vector<int> V2 = {1, 2, 3};
  auto result_2 = V2.data();
  ASSERT_NE(result_1, nullptr);
  ASSERT_NE(result_2, nullptr);
}

TEST(TestVectorData, DataSecond) {
  s21::Vector<int> V;
  auto result_1 = V.data();
  std::vector<int> V2;
  auto result_2 = V2.data();
  ASSERT_EQ(result_1, nullptr);
  ASSERT_EQ(result_2, nullptr);
}

TEST(TestVectorEmpty, EmptyFirst) {
  s21::Vector<int> V = {1, 2, 3};
  auto result_1 = V.empty();
  std::vector<int> V2 = {1, 2, 3};
  auto result_2 = V2.empty();
  ASSERT_EQ(result_1, false);
  ASSERT_EQ(result_2, false);
}

TEST(TestVectorEmpty, EmptySecond) {
  s21::Vector<int> V;
  auto result_1 = V.empty();
  std::vector<int> V2;
  auto result_2 = V2.empty();
  ASSERT_EQ(result_1, true);
  ASSERT_EQ(result_2, true);
}

TEST(TestVectorSize, SizeFirst) {
  s21::Vector<int> V = {1, 2, 3};
  auto result_1 = V.size();
  std::vector<int> V2 = {1, 2, 3};
  auto result_2 = V2.size();
  ASSERT_EQ(result_1, result_2);
}

TEST(TestVectorSize, SizeSecond) {
  s21::Vector<int> V;
  auto result_1 = V.size();
  std::vector<int> V2;
  auto result_2 = V2.size();
  ASSERT_EQ(result_1, result_2);
}

TEST(TestVectorCapacity, CapacityFirst) {
  s21::Vector<int> V = {1, 2, 3};
  auto result_1 = V.capacity();
  std::vector<int> V2 = {1, 2, 3};
  auto result_2 = V2.capacity();
  ASSERT_EQ(result_1, result_2);
}

TEST(TestVectorCapacity, CapacitySecond) {
  s21::Vector<int> V;
  auto result_1 = V.capacity();
  std::vector<int> V2;
  auto result_2 = V2.capacity();
  ASSERT_EQ(result_1, result_2);
}

TEST(TestVectorMaxSize, MaxSizeFirst) {
  s21::Vector<int> V = {1, 2, 3};
  auto result_1 = V.max_size();
  std::vector<int> V2 = {1, 2, 3};
  auto result_2 = V2.max_size();
  ASSERT_EQ(result_1, result_2);
}

TEST(TestVectorMaxSize, MaxSizeSecond) {
  s21::Vector<int> V;
  auto result_1 = V.max_size();
  std::vector<int> V2;
  auto result_2 = V2.max_size();
  ASSERT_EQ(result_1, result_2);
}

TEST(TestVectorMaxSize, MaxSizeThird) {
  s21::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  auto result_1 = V.max_size();
  auto result_2 = V2.max_size();
  ASSERT_EQ(result_1, result_2);
}

TEST(TestVectorReserve, ReserveFirst) {
  s21::Vector<int> V = {1, 2, 3};
  V.reserve(6);
  std::vector<int> V2 = {1, 2, 3};
  V2.reserve(6);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
}

TEST(TestVectorReserve, ReserveSecond) {
  s21::Vector<int> V;
  V.reserve(5);
  std::vector<int> V2;
  V2.reserve(5);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
}

TEST(TestVectorSwap, SwapFirst) {
  s21::Vector<int> V = {1, 2, 3};
  s21::Vector<int> V3 = {3, 2, 1};
  V.swap(V3);
  std::vector<int> V2 = {1, 2, 3};
  std::vector<int> V4 = {3, 2, 1};
  V2.swap(V4);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(*(V3.begin()), *(V4.begin()));
}

TEST(TestVectorSwap, SwapSecond) {
  s21::Vector<int> V = {1, 2};
  s21::Vector<int> V3 = {4, 5, 6};
  V.swap(V3);
  std::vector<int> V2 = {1, 2};
  std::vector<int> V4 = {4, 5, 6};
  V2.swap(V4);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(*(V3.begin()), *(V4.begin()));
}

TEST(TestVectorSwap, SwapThird) {
  s21::Vector<int> V = {1, 2, 3, 6, 7, 3, 6, 2, 4};
  s21::Vector<int> V3 = {3};
  V.swap(V3);
  std::vector<int> V2 = {1, 2, 3, 6, 7, 3, 6, 2, 4};
  std::vector<int> V4 = {3};
  V2.swap(V4);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(*(V3.begin()), *(V4.begin()));
}

TEST(TestVectorSwap, SwapFourth) {
  s21::Vector<int> V = {1};
  s21::Vector<int> V3 = {4};
  V.swap(V3);
  std::vector<int> V2 = {1};
  std::vector<int> V4 = {4};
  V2.swap(V4);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(*(V3.begin()), *(V4.begin()));
}

TEST(TestVectorSwap, SwapFifth) {
  s21::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  s21::Vector<std::string> V3 = {"is", "not", "one", "word"};
  V.swap(V3);
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  std::vector<std::string> V4 = {"is", "not", "one", "word"};
  V2.swap(V4);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(*(V3.begin()), *(V4.begin()));
}

TEST(TestVectorSwap, SwapSixth) {
  s21::Vector<std::string> V3 = {"a", "b", "c", "d", "f"};
  s21::Vector<std::string> V = {"is", "not", "one", "word"};
  V.swap(V3);
  std::vector<std::string> V4 = {"a", "b", "c", "d", "f"};
  std::vector<std::string> V2 = {"is", "not", "one", "word"};
  V2.swap(V4);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(*(V3.begin()), *(V4.begin()));
}

TEST(TestVectorOperator, OperatorFirst) {
  s21::Vector<int> V = {4, 6, 8, 10};
  s21::Vector<int> V3 = {2, 5};
  V = std::move(V3);
  std::vector<int> V2 = {4, 6, 8, 10};
  std::vector<int> V4 = {2, 5};
  V2 = std::move(V4);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(V[1], V2[1]);
}

TEST(TestVectorOperator, OperatorSecond) {
  s21::Vector<int> V = {2, 5};
  s21::Vector<int> V3 = {4, 6, 8, 10};
  V = std::move(V3);
  std::vector<int> V2 = {2, 5};
  std::vector<int> V4 = {4, 6, 8, 10};
  V2 = std::move(V4);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(V[1], V2[1]);
  ASSERT_EQ(V[2], V2[2]);
  ASSERT_EQ(V[3], V2[3]);
}

TEST(TestVectorOperator, OperatorThird) {
  s21::Vector<int> V = {1, 2, 3, 6, 7, 3, 6, 2};
  s21::Vector<int> V3 = {1, 2, 3, 6, 7, 3, 6, 2, 4};
  V = std::move(V3);
  std::vector<int> V2 = {1, 2, 3, 6, 7, 3, 6, 2};
  std::vector<int> V4 = {1, 2, 3, 6, 7, 3, 6, 2, 4};
  V2 = std::move(V4);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(V[1], V2[1]);
  ASSERT_EQ(V[2], V2[2]);
  ASSERT_EQ(V[3], V2[3]);
}

TEST(TestVectorOperator, OperatorFourth) {
  s21::Vector<int> V = {4, 6, 8, 10};
  s21::Vector<int> V3 = {2, 5};
  V = V3;
  std::vector<int> V2 = {4, 6, 8, 10};
  std::vector<int> V4 = {2, 5};
  V2 = V4;
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(V[1], V2[1]);
}

TEST(TestVectorOperator, OperatorFifth) {
  s21::Vector<int> V = {2, 5};
  s21::Vector<int> V3 = {4, 6, 8, 10};
  V = V3;
  std::vector<int> V2 = {2, 5};
  std::vector<int> V4 = {4, 6, 8, 10};
  V2 = V4;
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(V[1], V2[1]);
  ASSERT_EQ(V[2], V2[2]);
  ASSERT_EQ(V[3], V2[3]);
}

TEST(TestVectorOperator, OperatorSixth) {
  s21::Vector<int> V = {1, 2, 3, 6, 7, 3, 6, 2};
  s21::Vector<int> V3 = {1, 2, 3, 6, 7, 3, 6, 2, 4};
  V = V3;
  std::vector<int> V2 = {1, 2, 3, 6, 7, 3, 6, 2};
  std::vector<int> V4 = {1, 2, 3, 6, 7, 3, 6, 2, 4};
  V2 = V4;
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(V[1], V2[1]);
  ASSERT_EQ(V[2], V2[2]);
  ASSERT_EQ(V[3], V2[3]);
}

TEST(TestVectorOperator, OperatorSeventh) {
  s21::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  s21::Vector<std::string> V3 = {"it", "is", "not", "one", "word"};
  V = V3;
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  std::vector<std::string> V4 = {"it", "is", "not", "one", "word"};
  V2 = V4;
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(V[1], V2[1]);
  ASSERT_EQ(V[2], V2[2]);
  ASSERT_EQ(V[3], V2[3]);
}

TEST(TestVectorOperator, OperatorEighth) {
  s21::Vector<std::string> V = {"it", "is", "not", "one", "word"};
  s21::Vector<std::string> V3 = {"a", "b", "c", "d", "f"};
  V = V3;
  std::vector<std::string> V4 = {"a", "b", "c", "d", "f"};
  std::vector<std::string> V2 = {"it", "is", "not", "one", "word"};
  V2 = V4;
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(V[1], V2[1]);
  ASSERT_EQ(V[2], V2[2]);
  ASSERT_EQ(V[3], V2[3]);
}

TEST(TestVectorAt, At) {
  s21::Vector<int> V = {1, 2};
  std::vector<int> V2 = {1, 2};
  EXPECT_ANY_THROW(V.at(2));
  EXPECT_ANY_THROW(V2.at(7));
}

TEST(TestVectorAt, AtSecond) {
  s21::Vector<int> V = {1, 2};
  std::vector<int> V2 = {1, 2};
  ASSERT_EQ(V.at(1), V2.at(1));
  ASSERT_EQ(V.at(0), V2.at(0));
}

TEST(TestVectorBrackets, Brackets) {
  s21::Vector<int> V = {1, 2};
  EXPECT_ANY_THROW(V[4]);
}

TEST(TestVectorBrackets, BracketsSecond) {
  s21::Vector<int> V = {1, 2};
  std::vector<int> V2 = {1, 2};
  ASSERT_EQ(V[0], V2[0]);
  ASSERT_EQ(V[1], V2[1]);
}

TEST(TestVectorIterator, IteratorFirst) {
  s21::Vector<int> V = {1, 2};
  auto it = V.begin();
  std::vector<int> V2 = {1, 2};
  auto iter = V2.begin();
  ASSERT_EQ(it + 1, *(iter + 1));
}

TEST(TestVectorIterator, IteratorSecond) {
  s21::Vector<int> V = {1, 2};
  auto it = V.end();
  std::vector<int> V2 = {1, 2};
  auto iter = V2.end();
  ASSERT_EQ(it - 2, *(iter - 2));
}

TEST(TestVectorIterator, IteratorThird) {
  s21::Vector<int> V = {1, 2};
  auto it = V.end();
  --it;
  std::vector<int> V2 = {1, 2};
  auto iter = V2.end();
  --iter;
  ASSERT_EQ(*it, *(iter));
}

TEST(TestVectorIterator, IteratorFourth) {
  s21::Vector<int> V = {1, 2};
  auto it = V.begin();
  std::vector<int> V2 = {1, 2};
  auto iter = V2.begin();
  ASSERT_EQ(*it, *iter);
}

TEST(TestVectorIterator, IteratorFifth) {
  s21::Vector<std::string> V = {"it", "is", "not", "one", "word"};
  auto it = V.cbegin();
  it++;
  it++;
  it++;
  it++;
  std::vector<std::string> V2 = {"it", "is", "not", "one", "word"};
  auto iter = V2.cbegin();
  iter++;
  iter++;
  iter++;
  iter++;
  ASSERT_EQ(*it, *iter);
}

TEST(TestVectorIterator, IteratorSixth) {
  s21::Vector<int> V = {1, 2};
  auto it = V.begin();
  ++it;
  std::vector<int> V2 = {1, 2};
  auto iter = V2.begin();
  ++iter;
  ASSERT_EQ(*it, *iter);
}

TEST(TestVectorIterator, IteratorSeventh) {
  s21::Vector<int> V = {1, 2};
  s21::Vector<int> V2 = {1, 2};
  auto it = V.begin();
  auto it2 = V2.begin();
  std::vector<int> V3 = {1, 2};
  std::vector<int> V4 = {1, 2};
  auto iter = V3.begin();
  auto iter2 = V4.begin();
  ASSERT_EQ(it != it2, iter != iter2);
}

TEST(TestVectorIterator, IteratorEighth) {
  s21::Vector<int> V = {1, 2};
  s21::Vector<int> V2 = {1, 2};
  auto it = V.begin();
  auto it2 = V2.begin();
  std::vector<int> V3 = {1, 2};
  std::vector<int> V4 = {1, 2};
  auto iter = V3.begin();
  auto iter2 = V4.begin();
  ASSERT_EQ(it == it2, iter == iter2);
}

TEST(TestVectorIterator, IteratorNinth) {
  s21::Vector<int> V = {1, 2, 3, 4, 5, 7, 10};
  s21::Vector<int> V2 = {1, 2, 3, 4, 5, 7, 10};
  auto it = V.begin();
  it++;
  it++;
  it++;
  it--;
  auto iter = V2.begin();
  iter++;
  iter++;
  iter++;
  iter--;
  ASSERT_EQ(*it, *iter);
}

TEST(TestVectorIterator, IteratorTenth) {
  s21::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  ASSERT_EQ(it < it2, iter < iter2);
}

TEST(TestVectorIterator, IteratorEleventh) {
  s21::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  ASSERT_EQ(it > it2, iter > iter2);
}

TEST(TestVectorIterator, IteratorTwelfth) {
  s21::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  it2++;
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  iter2++;
  ASSERT_EQ(it <= it2, iter < iter2);
}

TEST(TestVectorIterator, IteratorThirteenth) {
  s21::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  it2++;
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  iter2++;
  ASSERT_EQ(it >= it2, iter >= iter2);
}

TEST(TestVectorIteratorConst, IteratorConstFirst) {
  s21::Vector<int> V = {1, 2};
  auto it = V.cbegin();
  std::vector<int> V2 = {1, 2};
  auto iter = V2.cbegin();
  ASSERT_EQ(it + 1, *(iter + 1));
}

TEST(TestVectorIteratorConst, IteratorConstSecond) {
  s21::Vector<int> V = {1, 2};
  auto it = V.cend();
  std::vector<int> V2 = {1, 2};
  auto iter = V2.cend();
  ASSERT_EQ(it - 2, *(iter - 2));
}

TEST(TestVectorIteratorConst, IteratorConstThird) {
  s21::Vector<int> V = {1, 2};
  auto it = V.cend();
  --it;
  std::vector<int> V2 = {1, 2};
  auto iter = V2.cend();
  --iter;
  ASSERT_EQ(*it, *(iter));
}

TEST(TestVectorIteratorConst, IteratorFourthConst) {
  s21::Vector<int> V = {1, 2};
  auto it = V.cbegin();
  std::vector<int> V2 = {1, 2};
  auto iter = V2.cbegin();
  ASSERT_EQ(*it, *iter);
}

TEST(TestVectorIteratorConst, IteratorFifthConst) {
  s21::Vector<std::string> V = {"it", "is", "not", "one", "word"};
  auto it = V.cbegin();
  it++;
  it++;
  it++;
  it++;
  std::vector<std::string> V2 = {"it", "is", "not", "one", "word"};
  auto iter = V2.cbegin();
  iter++;
  iter++;
  iter++;
  iter++;
  ASSERT_EQ(*it, *iter);
}

TEST(TestVectorIteratorConst, IteratorSixthConst) {
  s21::Vector<int> V = {1, 2};
  auto it = V.cbegin();
  ++it;
  std::vector<int> V2 = {1, 2};
  auto iter = V2.cbegin();
  ++iter;
  ASSERT_EQ(*it, *iter);
}

TEST(TestVectorIteratorConst, IteratorSeventhConst) {
  s21::Vector<int> V = {1, 2};
  s21::Vector<int> V2 = {1, 2};
  auto it = V.cbegin();
  auto it2 = V2.cbegin();
  std::vector<int> V3 = {1, 2};
  std::vector<int> V4 = {1, 2};
  auto iter = V3.cbegin();
  auto iter2 = V4.cbegin();
  ASSERT_EQ(it != it2, iter != iter2);
}

TEST(TestVectorIteratorConst, IteratorEighthConst) {
  s21::Vector<int> V = {1, 2};
  s21::Vector<int> V2 = {1, 2};
  auto it = V.cbegin();
  auto it2 = V2.cbegin();
  std::vector<int> V3 = {1, 2};
  std::vector<int> V4 = {1, 2};
  auto iter = V3.cbegin();
  auto iter2 = V4.cbegin();
  ASSERT_EQ(it == it2, iter == iter2);
}

TEST(TestVectorIteratorConst, IteratorNinthConst) {
  s21::Vector<int> V = {1, 2};
  s21::Vector<int> V2 = {3, 2};
  auto it = V.cbegin();
  auto it2 = V2.cbegin();
  std::vector<int> V3 = {1, 2};
  std::vector<int> V4 = {3, 2};
  auto iter = V3.cbegin();
  auto iter2 = V4.cbegin();
  it = it2;
  iter = iter2;
  ASSERT_EQ(*it, *iter);
}

TEST(TestVectorIteratorConst, IteratorConstTenth) {
  s21::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.cbegin();
  auto it2 = V.cbegin();
  it2++;
  it2++;
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.cbegin();
  auto iter2 = V2.cbegin();
  iter2++;
  iter2++;
  ASSERT_EQ(it < it2, iter < iter2);
}

TEST(TestVectorIteratorConst, IteratorConstEleventh) {
  s21::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.cbegin();
  auto it2 = V.cbegin();
  it2++;
  it2++;
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.cbegin();
  auto iter2 = V2.cbegin();
  iter2++;
  iter2++;
  ASSERT_EQ(it > it2, iter > iter2);
}

TEST(TestVectorIteratorConst, IteratorConstTwelfth) {
  s21::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.cbegin();
  auto it2 = V.cbegin();
  it2++;
  it2++;
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.cbegin();
  auto iter2 = V2.cbegin();
  iter2++;
  iter2++;
  ASSERT_EQ(it <= it2, iter < iter2);
}

TEST(TestVectorIteratorConst, IteratorConstThirteenth) {
  s21::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.cbegin();
  auto it2 = V.cbegin();
  it2++;
  it2++;
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.cbegin();
  auto iter2 = V2.cbegin();
  iter2++;
  iter2++;
  ASSERT_EQ(it >= it2, iter >= iter2);
}
