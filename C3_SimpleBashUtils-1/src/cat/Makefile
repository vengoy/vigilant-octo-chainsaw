CC=gcc -Wall -Wextra -Werror -std=c11

all: clean s21_cat

s21_cat:
	$(CC) s21_cat.c -o s21_cat

test:
	sh t_cat.sh

check:
	cp ../../materials/linters/CPPLINT.cfg ./
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	python3 ../../materials/linters/cpplint.py --extensions=c *.c *.h
	leaks -atExit -- ./s21_cat -b -n -s -v bytes.txt

clean:
	rm -rf test a.out s21_cat log.txt CPPLINT.cfg
