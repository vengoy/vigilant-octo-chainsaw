FLAGS = -Wall -Werror -Wextra
FFLAGS = -fprofile-arcs -ftest-coverage
all: s21_math.a html

s21_math.a: s21_math.o
	ar rcs s21_math.a $?

s21_math.o: s21_math.c s21_math.h
	gcc $(FLAGS) -c s21_math.c -o s21_math.o

test: s21_math.o
	gcc $(FFLAGS) math_test.c s21_math.c -lcheck -o test.o
	./test.o

gcov_report: test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info

html: gcov_report
	open report/index.html

clean:
	@rm -rf *.o *.info *.gcda *.gcno *.out *.a report
