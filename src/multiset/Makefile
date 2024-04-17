
G++ = g++ -std=c++17
CHECKFLAGS = -Wall -Werror -Wextra
TEST_LIBS = -lgtest -lgtest_main -pthread
NAME_TESTS = *_test.cc
NAME_EXE = set

all: clean test

build: format
	@$(G++) $(CHECKFLAGS) main.cc
	./a.out
	@rm a.out

test: 
	@$(G++) $(CHECKFLAGS) *$(NAME_TESTS) -o $(NAME_EXE) $(TEST_LIBS) -g 
	./$(NAME_EXE)

clean:
	@rm -rf *.o *.a a.out *.css *.html gcov_test *.gcda *.gcno $(NAME_EXE) info gcovreport.info report set.dSYM

format: 
	@clang-format -style=google -i *.cc
	@clang-format -style=google -i *.h

clang-format: 
	clang-format -style=google -n *.cc
	clang-format -style=google -n *.h

fsanitize: 
	$(G++)  $(NAME_TESTS)  $(CHECKFLAGS) -g -fsanitize=address $(TEST_LIBS) -o $(NAME_EXE)
	./$(NAME_EXE)

valgrind: test
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME_EXE)
