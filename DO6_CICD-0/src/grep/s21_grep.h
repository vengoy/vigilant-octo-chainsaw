#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s21_grep {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int error;
  int f_cnt;
  char *temp;
  char str_error;
} flags;

void parse_input(int argc, char *argv[]);
void parse_flags(char *str, flags *q, int *n, char *argv[]);
void e_str(char *pt, flags *q);
void f_str(char *name, flags *q);
void formated_print(char *str, flags *q);
void find_print(char const *name, char *str, int cnt, flags *q);
void flag_lc(char *str, int line_cnt, flags *q);
void file_process(char const *str, FILE *fp, regex_t *reg, int *line_cnt,
                  flags *q);

#endif  //  SRC_GREP_S21_GREP_H_
