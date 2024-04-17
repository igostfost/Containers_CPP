G++ = g++ -std=c++17
CHECKFLAGS = -Wall -Werror -Wextra
TEST_SRC = s21_map_test.cc
TEST_LIBS = -lgtest -pthread 

all: clean test

test: 
	$(G++) $(CHECKFLAGS) $(TEST_SRC) $(TEST_LIBS) -o test
	./test
	rm test

clean:
	rm -rf *.o *.a a.out *.css *.html gcov_test *.gcda *.gcno test 

gcov_report:
	$(G++) --coverage $(TEST_SRC) $(TEST_LIBS) -o gcov_test $(shell pkg-config --libs --cflags check)
	./gcov_test
	gcovr -r . --html --html-details -o containers.html
	open ./containers.html

style: 
	clang-format -style=google -i *.cc
	clang-format -style=google -i *.h

clang-format: 
	clang-format -style=google -n *.cc
	clang-format -style=google -n *.h

valgrind: test
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./test
