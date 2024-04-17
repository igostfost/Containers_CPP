# Главный мейкфайл
G++ = g++ -std=c++17
CHECKFLAGS = -Wall -Werror -Wextra
TEST_LIBS = -lgtest -lgtest_main -pthread
ifeq ($(OS), Linux)
  OPEN=xdg-open
else
  OPEN=open
endif

NAME_TESTS = test.cc
NAME_EXE = test


all: clean test

.PHONY: test

test: 
	@$(G++) $(CHECKFLAGS) */*$(NAME_TESTS) -o $(NAME_EXE) $(TEST_LIBS) -g 
	@./$(NAME_EXE)

clean:
	@rm -rf *.o *.a a.out *.css *.html gcov_test *.gcda *.gcno $(NAME_EXE) info gcovreport.info report test.dSYM 

gcov_report: clean
	@$(G++) $(CHECKFLAGS) */*$(NAME_TESTS) $(TEST_LIBS) -coverage -o info
	@./info
	@lcov -t "info" -o gcovreport.info -c -d .
	@lcov --remove gcovreport.info '/usr/*' '*test*' --output-file gcovreport.info
	@genhtml -o report gcovreport.info
	@$(OPEN) report/index.html

format: 
	@clang-format -style=google -i */*.cc
	@clang-format -style=google -i */*.h

clang-format: 
	@clang-format -style=google -n */*.cc
	@clang-format -style=google -n */*.h

fsanitize: 
	@$(G++) */*$(NAME_TESTS) $(CHECKFLAGS) -g -fsanitize=address $(TEST_LIBS) -o $(NAME_EXE) 
	./$(NAME_EXE)
	@rm $(NAME_EXE)

valgrind: test
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME_EXE)