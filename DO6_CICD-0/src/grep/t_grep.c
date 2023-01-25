#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"

void test_1(int *i, int *t, int *f);
void test_2(int *i, int *t, int *f);
void test_3(int *i, int *t, int *f);
void test_4(int *i, int *t, int *f);
void test_5(int *i, int *t, int *f);
void test_6(int *i, int *t, int *f);
void test_7(int *i, int *t, int *f);
void test_8(int *i, int *t, int *f);

int testing(char *str, int i, int *t, int *f);
int compareFile(FILE *fPtr1, FILE *fPtr2, int *line, int *col);

int main() {
  int i = 1;
  int t = 0;
  int f = 0;
  test_1(&i, &t, &f);
  test_2(&i, &t, &f);
  test_3(&i, &t, &f);
  test_4(&i, &t, &f);
  test_5(&i, &t, &f);
  test_6(&i, &t, &f);
  test_7(&i, &t, &f);
  test_8(&i, &t, &f);

  printf(" ------------- \n");
  printf("| SUCCESS: %d |\n", t);
  printf(" ------------- \n");
  printf("| FAILURE: %d |\n", f);
  printf(" ------------- \n");
}
void test_1(int *i, int *t, int *f) {
  *i = testing("for s21_grep.c s21_grep.h Makefile -v -c -l", *i, t, f);
  *i = testing("for s21_grep.c -v -c -l", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -v -c -l", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -v -c -l", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -v -c -l -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -v -c -l -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -v -c -n", *i, t, f);
  *i = testing("for s21_grep.c -v -c -n", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -v -c -n", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -v -c -n", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -v -c -n -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -v -c -n -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -v -c -h", *i, t, f);
  *i = testing("for s21_grep.c -v -c -h", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -v -c -h", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -v -c -h", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -v -c -h -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -v -c -h -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -v -c -o", *i, t, f);
  *i = testing("for s21_grep.c -v -c -o", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -v -c -o", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -v -c -o", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -v -c -o -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -v -c -o -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -v -l -c", *i, t, f);
  *i = testing("for s21_grep.c -v -l -c", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -v -l -c", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -v -l -c", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -v -l -c -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -v -l -c -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -v -l -n", *i, t, f);
  *i = testing("for s21_grep.c -v -l -n", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -v -l -n", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -v -l -n", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -v -l -n -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -v -l -n -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -v -l -h", *i, t, f);
  *i = testing("for s21_grep.c -v -l -h", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -v -l -h", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -v -l -h", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -v -l -h -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -v -l -h -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -v -l -o", *i, t, f);
  *i = testing("for s21_grep.c -v -l -o", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -v -l -o", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -v -l -o", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -v -l -o -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -v -l -o -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -v -n -c", *i, t, f);
  *i = testing("for s21_grep.c -v -n -c", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -v -n -c", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -v -n -c", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -v -n -c -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -v -n -c -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -v -n -l", *i, t, f);
  *i = testing("for s21_grep.c -v -n -l", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -v -n -l", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -v -n -l", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -v -n -l -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -v -n -l -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c -v -n -h", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c -v -n -h", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -v -n -h -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -v -n -h -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c -v -n -o", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c -v -n -o", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -v -n -o -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -v -n -o -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -v -h -c", *i, t, f);
  *i = testing("for s21_grep.c -v -h -c", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -v -h -c", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -v -h -c", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -v -h -c -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -v -h -c -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -v -h -l", *i, t, f);
  *i = testing("for s21_grep.c -v -h -l", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -v -h -l", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -v -h -l", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -v -h -l -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -v -h -l -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c -v -h -n", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c -v -h -n", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -v -h -n -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -v -h -n -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -v -h -o", *i, t, f);
  *i = testing("for s21_grep.c -v -h -o", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -v -h -o", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -v -h -o", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -v -h -o -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -v -h -o -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -v -o -c", *i, t, f);
  *i = testing("for s21_grep.c -v -o -c", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -v -o -c", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -v -o -c", *i, t, f);
}
void test_2(int *i, int *t, int *f) {
  *i = testing("-e regex -e ^print s21_grep.c -v -o -c -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -v -o -c -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -v -o -l", *i, t, f);
  *i = testing("for s21_grep.c -v -o -l", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -v -o -l", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -v -o -l", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -v -o -l -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -v -o -l -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c -v -o -n", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c -v -o -n", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -v -o -n -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -v -o -n -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -v -o -h", *i, t, f);
  *i = testing("for s21_grep.c -v -o -h", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -v -o -h", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -v -o -h", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -v -o -h -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -v -o -h -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -c -v -l", *i, t, f);
  *i = testing("for s21_grep.c -c -v -l", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -c -v -l", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -c -v -l", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -c -v -l -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -c -v -l -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -c -v -n", *i, t, f);
  *i = testing("for s21_grep.c -c -v -n", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -c -v -n", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -c -v -n", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -c -v -n -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -c -v -n -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -c -v -h", *i, t, f);
  *i = testing("for s21_grep.c -c -v -h", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -c -v -h", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -c -v -h", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -c -v -h -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -c -v -h -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -c -v -o", *i, t, f);
  *i = testing("for s21_grep.c -c -v -o", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -c -v -o", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -c -v -o", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -c -v -o -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -c -v -o -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -c -l -v", *i, t, f);
  *i = testing("for s21_grep.c -c -l -v", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -c -l -v", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -c -l -v", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -c -l -v -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -c -l -v -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -c -l -n", *i, t, f);
  *i = testing("for s21_grep.c -c -l -n", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -c -l -n", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -c -l -n", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -c -l -n -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -c -l -n -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -c -l -h", *i, t, f);
  *i = testing("for s21_grep.c -c -l -h", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -c -l -h", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -c -l -h", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -c -l -h -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -c -l -h -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -c -l -o", *i, t, f);
  *i = testing("for s21_grep.c -c -l -o", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -c -l -o", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -c -l -o", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -c -l -o -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -c -l -o -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -c -n -v", *i, t, f);
  *i = testing("for s21_grep.c -c -n -v", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -c -n -v", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -c -n -v", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -c -n -v -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -c -n -v -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -c -n -l", *i, t, f);
  *i = testing("for s21_grep.c -c -n -l", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -c -n -l", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -c -n -l", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -c -n -l -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -c -n -l -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -c -n -h", *i, t, f);
  *i = testing("for s21_grep.c -c -n -h", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -c -n -h", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -c -n -h", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -c -n -h -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -c -n -h -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -c -n -o", *i, t, f);
  *i = testing("for s21_grep.c -c -n -o", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -c -n -o", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -c -n -o", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -c -n -o -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -c -n -o -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -c -h -v", *i, t, f);
  *i = testing("for s21_grep.c -c -h -v", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -c -h -v", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -c -h -v", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -c -h -v -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -c -h -v -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -c -h -l", *i, t, f);
}
void test_3(int *i, int *t, int *f) {
  *i = testing("for s21_grep.c -c -h -l", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -c -h -l", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -c -h -l", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -c -h -l -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -c -h -l -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -c -h -n", *i, t, f);
  *i = testing("for s21_grep.c -c -h -n", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -c -h -n", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -c -h -n", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -c -h -n -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -c -h -n -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -c -h -o", *i, t, f);
  *i = testing("for s21_grep.c -c -h -o", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -c -h -o", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -c -h -o", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -c -h -o -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -c -h -o -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -c -o -v", *i, t, f);
  *i = testing("for s21_grep.c -c -o -v", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -c -o -v", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -c -o -v", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -c -o -v -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -c -o -v -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -c -o -l", *i, t, f);
  *i = testing("for s21_grep.c -c -o -l", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -c -o -l", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -c -o -l", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -c -o -l -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -c -o -l -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -c -o -n", *i, t, f);
  *i = testing("for s21_grep.c -c -o -n", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -c -o -n", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -c -o -n", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -c -o -n -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -c -o -n -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -c -o -h", *i, t, f);
  *i = testing("for s21_grep.c -c -o -h", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -c -o -h", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -c -o -h", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -c -o -h -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -c -o -h -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -l -v -c", *i, t, f);
  *i = testing("for s21_grep.c -l -v -c", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -l -v -c", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -l -v -c", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -l -v -c -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -l -v -c -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -l -v -n", *i, t, f);
  *i = testing("for s21_grep.c -l -v -n", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -l -v -n", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -l -v -n", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -l -v -n -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -l -v -n -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -l -v -h", *i, t, f);
  *i = testing("for s21_grep.c -l -v -h", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -l -v -h", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -l -v -h", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -l -v -h -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -l -v -h -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -l -v -o", *i, t, f);
  *i = testing("for s21_grep.c -l -v -o", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -l -v -o", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -l -v -o", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -l -v -o -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -l -v -o -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -l -c -v", *i, t, f);
  *i = testing("for s21_grep.c -l -c -v", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -l -c -v", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -l -c -v", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -l -c -v -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -l -c -v -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -l -c -n", *i, t, f);
  *i = testing("for s21_grep.c -l -c -n", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -l -c -n", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -l -c -n", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -l -c -n -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -l -c -n -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -l -c -h", *i, t, f);
  *i = testing("for s21_grep.c -l -c -h", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -l -c -h", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -l -c -h", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -l -c -h -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -l -c -h -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -l -c -o", *i, t, f);
  *i = testing("for s21_grep.c -l -c -o", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -l -c -o", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -l -c -o", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -l -c -o -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -l -c -o -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -l -n -v", *i, t, f);
  *i = testing("for s21_grep.c -l -n -v", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -l -n -v", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -l -n -v", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -l -n -v -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -l -n -v -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -l -n -c", *i, t, f);
  *i = testing("for s21_grep.c -l -n -c", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -l -n -c", *i, t,
               f);
}
void test_4(int *i, int *t, int *f) {
  *i = testing("-e for -e ^int s21_grep.c -l -n -c", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -l -n -c -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -l -n -c -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -l -n -h", *i, t, f);
  *i = testing("for s21_grep.c -l -n -h", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -l -n -h", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -l -n -h", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -l -n -h -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -l -n -h -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -l -n -o", *i, t, f);
  *i = testing("for s21_grep.c -l -n -o", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -l -n -o", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -l -n -o", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -l -n -o -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -l -n -o -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -l -h -v", *i, t, f);
  *i = testing("for s21_grep.c -l -h -v", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -l -h -v", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -l -h -v", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -l -h -v -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -l -h -v -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -l -h -c", *i, t, f);
  *i = testing("for s21_grep.c -l -h -c", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -l -h -c", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -l -h -c", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -l -h -c -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -l -h -c -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -l -h -n", *i, t, f);
  *i = testing("for s21_grep.c -l -h -n", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -l -h -n", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -l -h -n", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -l -h -n -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -l -h -n -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -l -h -o", *i, t, f);
  *i = testing("for s21_grep.c -l -h -o", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -l -h -o", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -l -h -o", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -l -h -o -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -l -h -o -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -l -o -v", *i, t, f);
  *i = testing("for s21_grep.c -l -o -v", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -l -o -v", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -l -o -v", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -l -o -v -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -l -o -v -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -l -o -c", *i, t, f);
  *i = testing("for s21_grep.c -l -o -c", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -l -o -c", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -l -o -c", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -l -o -c -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -l -o -c -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -l -o -n", *i, t, f);
  *i = testing("for s21_grep.c -l -o -n", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -l -o -n", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -l -o -n", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -l -o -n -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -l -o -n -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -l -o -h", *i, t, f);
  *i = testing("for s21_grep.c -l -o -h", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -l -o -h", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -l -o -h", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -l -o -h -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -l -o -h -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -n -v -c", *i, t, f);
  *i = testing("for s21_grep.c -n -v -c", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -n -v -c", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -n -v -c", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -n -v -c -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -n -v -c -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -n -v -l", *i, t, f);
  *i = testing("for s21_grep.c -n -v -l", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -n -v -l", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -n -v -l", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -n -v -l -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -n -v -l -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c -n -v -h", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c -n -v -h", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -n -v -h -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -n -v -h -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c -n -v -o", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c -n -v -o", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -n -v -o -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -n -v -o -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -n -c -v", *i, t, f);
  *i = testing("for s21_grep.c -n -c -v", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -n -c -v", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -n -c -v", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -n -c -v -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -n -c -v -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -n -c -l", *i, t, f);
  *i = testing("for s21_grep.c -n -c -l", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -n -c -l", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -n -c -l", *i, t, f);
}
void test_5(int *i, int *t, int *f) {
  *i = testing("-e regex -e ^print s21_grep.c -n -c -l -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -n -c -l -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -n -c -h", *i, t, f);
  *i = testing("for s21_grep.c -n -c -h", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -n -c -h", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -n -c -h", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -n -c -h -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -n -c -h -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -n -c -o", *i, t, f);
  *i = testing("for s21_grep.c -n -c -o", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -n -c -o", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -n -c -o", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -n -c -o -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -n -c -o -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -n -l -v", *i, t, f);
  *i = testing("for s21_grep.c -n -l -v", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -n -l -v", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -n -l -v", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -n -l -v -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -n -l -v -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -n -l -c", *i, t, f);
  *i = testing("for s21_grep.c -n -l -c", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -n -l -c", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -n -l -c", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -n -l -c -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -n -l -c -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -n -l -h", *i, t, f);
  *i = testing("for s21_grep.c -n -l -h", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -n -l -h", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -n -l -h", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -n -l -h -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -n -l -h -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -n -l -o", *i, t, f);
  *i = testing("for s21_grep.c -n -l -o", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -n -l -o", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -n -l -o", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -n -l -o -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -n -l -o -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c -n -h -v", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c -n -h -v", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -n -h -v -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -n -h -v -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -n -h -c", *i, t, f);
  *i = testing("for s21_grep.c -n -h -c", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -n -h -c", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -n -h -c", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -n -h -c -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -n -h -c -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -n -h -l", *i, t, f);
  *i = testing("for s21_grep.c -n -h -l", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -n -h -l", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -n -h -l", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -n -h -l -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -n -h -l -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -n -h -o", *i, t, f);
  *i = testing("for s21_grep.c -n -h -o", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -n -h -o", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -n -h -o", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -n -h -o -f pattern.txt", *i, t,
               f);
  *i = testing("for s21_grep.c -n -o -v", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c -n -o -v", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -n -o -v -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -n -o -v -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -n -o -c", *i, t, f);
  *i = testing("for s21_grep.c -n -o -c", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -n -o -c", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -n -o -c", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -n -o -c -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -n -o -c -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -n -o -l", *i, t, f);
  *i = testing("for s21_grep.c -n -o -l", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -n -o -l", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -n -o -l", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -n -o -l -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -n -o -l -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -n -o -h", *i, t, f);
  *i = testing("for s21_grep.c -n -o -h", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -n -o -h", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -n -o -h", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -n -o -h -f pattern.txt", *i, t,
               f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -h -v -c", *i, t, f);
  *i = testing("for s21_grep.c -h -v -c", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -h -v -c", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -h -v -c", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -h -v -c -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -h -v -c -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -h -v -l", *i, t, f);
  *i = testing("for s21_grep.c -h -v -l", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -h -v -l", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -h -v -l", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -h -v -l -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -h -v -l -f pattern.txt",
               *i, t, f);
}
void test_6(int *i, int *t, int *f) {
  *i = testing("for s21_grep.c -h -v -n", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c -h -v -n", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -h -v -n -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -h -v -n -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -h -v -o", *i, t, f);
  *i = testing("for s21_grep.c -h -v -o", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -h -v -o", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -h -v -o", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -h -v -o -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -h -v -o -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -h -c -v", *i, t, f);
  *i = testing("for s21_grep.c -h -c -v", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -h -c -v", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -h -c -v", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -h -c -v -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -h -c -v -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -h -c -l", *i, t, f);
  *i = testing("for s21_grep.c -h -c -l", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -h -c -l", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -h -c -l", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -h -c -l -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -h -c -l -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -h -c -n", *i, t, f);
  *i = testing("for s21_grep.c -h -c -n", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -h -c -n", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -h -c -n", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -h -c -n -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -h -c -n -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -h -c -o", *i, t, f);
  *i = testing("for s21_grep.c -h -c -o", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -h -c -o", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -h -c -o", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -h -c -o -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -h -c -o -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -h -l -v", *i, t, f);
  *i = testing("for s21_grep.c -h -l -v", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -h -l -v", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -h -l -v", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -h -l -v -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -h -l -v -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -h -l -c", *i, t, f);
  *i = testing("for s21_grep.c -h -l -c", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -h -l -c", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -h -l -c", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -h -l -c -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -h -l -c -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -h -l -n", *i, t, f);
  *i = testing("for s21_grep.c -h -l -n", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -h -l -n", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -h -l -n", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -h -l -n -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -h -l -n -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -h -l -o", *i, t, f);
  *i = testing("for s21_grep.c -h -l -o", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -h -l -o", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -h -l -o", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -h -l -o -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -h -l -o -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c -h -n -v", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c -h -n -v", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -h -n -v -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -h -n -v -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -h -n -c", *i, t, f);
  *i = testing("for s21_grep.c -h -n -c", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -h -n -c", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -h -n -c", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -h -n -c -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -h -n -c -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -h -n -l", *i, t, f);
  *i = testing("for s21_grep.c -h -n -l", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -h -n -l", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -h -n -l", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -h -n -l -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -h -n -l -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -h -n -o", *i, t, f);
  *i = testing("for s21_grep.c -h -n -o", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -h -n -o", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -h -n -o", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -h -n -o -f pattern.txt", *i, t,
               f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -h -o -v", *i, t, f);
  *i = testing("for s21_grep.c -h -o -v", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -h -o -v", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -h -o -v", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -h -o -v -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -h -o -v -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -h -o -c", *i, t, f);
  *i = testing("for s21_grep.c -h -o -c", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -h -o -c", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -h -o -c", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -h -o -c -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -h -o -c -f pattern.txt",
               *i, t, f);
}
void test_7(int *i, int *t, int *f) {
  *i = testing("for s21_grep.c s21_grep.h Makefile -h -o -l", *i, t, f);
  *i = testing("for s21_grep.c -h -o -l", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -h -o -l", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -h -o -l", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -h -o -l -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -h -o -l -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -h -o -n", *i, t, f);
  *i = testing("for s21_grep.c -h -o -n", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -h -o -n", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -h -o -n", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -h -o -n -f pattern.txt", *i, t,
               f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -o -v -c", *i, t, f);
  *i = testing("for s21_grep.c -o -v -c", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -o -v -c", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -o -v -c", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -o -v -c -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -o -v -c -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -o -v -l", *i, t, f);
  *i = testing("for s21_grep.c -o -v -l", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -o -v -l", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -o -v -l", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -o -v -l -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -o -v -l -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c -o -v -n", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c -o -v -n", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -o -v -n -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -o -v -n -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -o -v -h", *i, t, f);
  *i = testing("for s21_grep.c -o -v -h", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -o -v -h", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -o -v -h", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -o -v -h -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -o -v -h -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -o -c -v", *i, t, f);
  *i = testing("for s21_grep.c -o -c -v", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -o -c -v", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -o -c -v", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -o -c -v -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -o -c -v -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -o -c -l", *i, t, f);
  *i = testing("for s21_grep.c -o -c -l", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -o -c -l", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -o -c -l", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -o -c -l -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -o -c -l -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -o -c -n", *i, t, f);
  *i = testing("for s21_grep.c -o -c -n", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -o -c -n", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -o -c -n", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -o -c -n -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -o -c -n -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -o -c -h", *i, t, f);
  *i = testing("for s21_grep.c -o -c -h", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -o -c -h", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -o -c -h", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -o -c -h -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -o -c -h -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -o -l -v", *i, t, f);
  *i = testing("for s21_grep.c -o -l -v", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -o -l -v", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -o -l -v", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -o -l -v -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -o -l -v -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -o -l -c", *i, t, f);
  *i = testing("for s21_grep.c -o -l -c", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -o -l -c", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -o -l -c", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -o -l -c -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -o -l -c -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -o -l -n", *i, t, f);
  *i = testing("for s21_grep.c -o -l -n", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -o -l -n", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -o -l -n", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -o -l -n -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -o -l -n -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -o -l -h", *i, t, f);
  *i = testing("for s21_grep.c -o -l -h", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -o -l -h", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -o -l -h", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -o -l -h -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -o -l -h -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c -o -n -v", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c -o -n -v", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -o -n -v -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -o -n -v -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -o -n -c", *i, t, f);
  *i = testing("for s21_grep.c -o -n -c", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -o -n -c", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -o -n -c", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -o -n -c -f pattern.txt", *i, t,
               f);
}
void test_8(int *i, int *t, int *f) {
  *i = testing("-e while -e void s21_grep.c Makefile -o -n -c -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -o -n -l", *i, t, f);
  *i = testing("for s21_grep.c -o -n -l", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -o -n -l", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -o -n -l", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -o -n -l -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -o -n -l -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -o -n -h", *i, t, f);
  *i = testing("for s21_grep.c -o -n -h", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -o -n -h", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -o -n -h", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -o -n -h -f pattern.txt", *i, t,
               f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -o -h -v", *i, t, f);
  *i = testing("for s21_grep.c -o -h -v", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -o -h -v", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -o -h -v", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -o -h -v -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -o -h -v -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -o -h -c", *i, t, f);
  *i = testing("for s21_grep.c -o -h -c", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -o -h -c", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -o -h -c", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -o -h -c -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -o -h -c -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -o -h -l", *i, t, f);
  *i = testing("for s21_grep.c -o -h -l", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -o -h -l", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -o -h -l", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -o -h -l -f pattern.txt", *i, t,
               f);
  *i = testing("-e while -e void s21_grep.c Makefile -o -h -l -f pattern.txt",
               *i, t, f);
  *i = testing("for s21_grep.c s21_grep.h Makefile -o -h -n", *i, t, f);
  *i = testing("for s21_grep.c -o -h -n", *i, t, f);
  *i = testing("-e for -e ^int s21_grep.c s21_grep.h Makefile -o -h -n", *i, t,
               f);
  *i = testing("-e for -e ^int s21_grep.c -o -h -n", *i, t, f);
  *i = testing("-e regex -e ^print s21_grep.c -o -h -n -f pattern.txt", *i, t,
               f);
}

int testing(char *str, int i, int *t, int *f) {
  char cmd1[100];
  memset(cmd1, '\0', 100);
  char cmd2[100];
  memset(cmd2, '\0', 100);
  sprintf(cmd1, "./s21_grep %s > out/s21.txt 2>&1", str);
  sprintf(cmd2, "grep %s > out/orig.txt 2>&1", str);
  printf("test #%-3d ", i);

  system(cmd1);
  system(cmd2);

  FILE *fPtr1;
  FILE *fPtr2;

  int diff;
  int line, col;

  fPtr1 = fopen("out/orig.txt", "r");
  fPtr2 = fopen("out/s21.txt", "r");

  if (fPtr1 == NULL || fPtr2 == NULL) {
    printf("ERROR: Unable to open file.");
    printf("Please check whether file exists and you have read privilege.");
    exit(EXIT_FAILURE);
  }

  diff = compareFile(fPtr1, fPtr2, &line, &col);

  if (diff == 0) {
    printf("%sSUCCESS: %s%s %s\n", KGRN, cmd1, cmd2, KNRM);
    *t += 1;
  } else {
    printf("%sFAIL: %s%s %s\n", KRED, cmd1, cmd2, KNRM);
    *f += 1;
  }
  fclose(fPtr1);
  fclose(fPtr2);
  return (i += 1);
}

int compareFile(FILE *fPtr1, FILE *fPtr2, int *line, int *col) {
  int ch1, ch2;
  *line = 1;
  *col = 0;
  do {
    ch1 = fgetc(fPtr1);
    ch2 = fgetc(fPtr2);
    if (ch1 == '\n') {
      *line += 1;
      *col = 0;
    }
    if (ch1 != ch2) return -1;
    *col += 1;
  } while (ch1 != EOF && ch2 != EOF);

  if (ch1 == EOF && ch2 == EOF)
    return 0;
  else
    return -1;
}
