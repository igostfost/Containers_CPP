
G++ = g++ -std=c++17
CHECKFLAGS = -Wall -Werror -Wextra
TEST_LIBS = -lgtest -lgtest_main -pthread
NAME_TESTS = test.cc
NAME_EXE = test_queue

all: clean test

test:
	$(G++) $(CHECKFLAGS) -std=c++17 -o $(NAME_EXE) $(NAME_TESTS) $(TEST_LIBS)
	./$(NAME_EXE)
	rm $(NAME_EXE)

clean:
	rm -rf *.o *.a a.out *.css *.html gcov_test *.gcda *.gcno $(NAME_EXE)

format: 
	clang-format -style=google -i *.cc
	clang-format -style=google -i *.h

clang-format: 
	clang-format -style=google -n *.cc
	clang-format -style=google -n *.h

fsanitize: 
	$(G++)  $(NAME_TESTS)  $(CHECKFLAGS) -g -fsanitize=address $(TEST_LIBS) -o $(NAME_EXE)
	./$(NAME_EXE)

valgrind: test
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME_EXE)
