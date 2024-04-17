
G++ = g++ -std=c++17
CHECKFLAGS = -Wall -Werror -Wextra
TEST_LIBS = -lgtest -lgtest_main -pthread
NAME_TESTS = s21_set_test.cc
NAME_EXE = set

all: clean test

test:
	$(G++) $(CHECKFLAGS) -o $(NAME_EXE) $(NAME_TESTS) $(TEST_LIBS)
	./$(NAME_EXE)
	rm $(NAME_EXE)

gcov_report: clean
	@$(G++) $(CHECKFLAGS) $(NAME_TESTS) $(TEST_LIBS) -coverage -o info
	@./info
	@lcov -t "info" -o gcovreport.info -c -d .
	@lcov --remove gcovreport.info '/usr/*' '*test*' --output-file gcovreport.info
	@genhtml -o report gcovreport.info
	@chmod +wr report/index.html
	
clean:
	@rm -rf *.o *.a a.out *.css *.html gcov_test *.gcda *.gcno $(NAME_EXE) info gcovreport.info report test.dSYM 

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
