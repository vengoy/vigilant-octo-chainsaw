#include "s21_cat.h"

int main(int argc, char *argv[]) {
  option_t opt = {0, 0, 0, 0, 0, 0};
  buffer_t buf = {0};
  bufInit(&buf);

  char **files = memoryStrArr();

  if (generalParsing(argc, argv, files, &buf, &opt)) {
    filesCycle(files, opt, &buf);
  }

  freeStrArr(files);
  return 0;
}

void filesCycle(char **files, option_t opt, buffer_t *buf) {
  for (int i = 0; i < buf->file_count; i++) {
    readFile(files[i], opt, buf);
  }
}

void readFile(char *fileName, option_t opt, buffer_t *buf) {
  FILE *fp;
  if ((fp = fopen(fileName, "r")) == NULL) {
    fileErrPrint("cat", 0, fileName);
    printf("cat: %s: No such file or directory\n", fileName);
  } else {
    cicle(opt, fp, buf);
    if (fclose(fp) == EOF) {
      fileErrPrint("cat", -1, fileName);
    }
  }
}

void cicle(option_t opt, FILE *fp, buffer_t *buf) {
  char ch = 0;
  while (ch != EOF) {
    if (fp == NULL) {
      ch = getchar();
    } else {
      ch = getc(fp);
    }
    if (ch != -1) {
      checkFlags(&opt, buf, ch);
      if (buf->emp == 1) {
        buf->emp = 0;
        buf->is_spec = 0;
        buf->pre_pre = buf->pre;
        buf->pre = ch;
        continue;
      }
      if (buf->is_spec == 0) {
        printf("%c", ch);
      }
    }
    buf->is_spec = 0;
    buf->pre_pre = buf->pre;
    buf->pre = ch;
  }
}

int generalParsing(int argc, char *argv[], char **files, buffer_t *buf,
                   option_t *opt) {
  int check = 1;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      if (argv[i][1] == '-') {
        if (!gnuOpt(argv[i], opt)) {
          check = 0;
          break;
        }
      } else {
        if (!macOpt(argv[i], opt)) {
          check = 0;
          break;
        }
      }
      re(opt);
    } else {
      strcpy(files[buf->file_count++], argv[i]);
    }
  }
  return check;
}

void re(option_t *opt) {
  if (opt->b == 1) opt->n = 0;
}

void checkFlags(option_t *opt, buffer_t *buf, char ch) {
  if (opt->s == 1 && flag_s(buf->pre_pre, buf->pre_pre, ch)) {
    buf->emp = 1;
  }
  if (opt->n == 1 && buf->emp != 1) {
    buf->start_line_flag = flag_n(buf, ch);
  }
  if (opt->b == 1 && buf->emp != 1) {
    flag_b(buf, ch);
  }
  if (opt->T == 1 && buf->emp != 1 && flag_T(ch)) {
    buf->emp = 1;
  }
  if (opt->E == 1 && buf->emp != 1) {
    flag_E(ch);
  }
  if (opt->v == 1 && buf->emp != 1) {
    buf->is_spec = flag_v(ch);
  }
}

void flag_b(buffer_t *buf, char ch) {
  if (buf->pre == '\n' && ch != '\n') {
    printf("%6d\t", (buf->num_non_emp_line)++);
  }
}

int flag_n(buffer_t *buf, char ch) {
  if (buf->start_line_flag) printf("%6d\t", (buf->num_non_emp_line)++);
  return (ch == '\n');
}

void flag_E(char ch) {
  if (ch == '\n') printf("$");
}

int flag_v(char c) {
  int result = 0;
  unsigned char uc = c;
  if (is_special(c)) {
    printf("%s", s21_cat_spec_symbols[uc]);
    result = 1;
  }
  return result;
}

int flag_T(char c) {
  int res = 0;
  if (c == '\t') res = printf("^I");
  return res;
}

int flag_s(char pre_pre, char pre, char c) {
  return (c == '\n' && pre == '\n' && pre_pre == '\n');
}

int is_special(unsigned char c) {
  return (c <= 8) || (c >= 11 && c <= 31) || (c >= 127 && c <= 159);
}

int gnuOpt(char *str, option_t *opt) {
  int check = 1;
  if (!strcmp(str, "--number-nonblank")) {
    opt->b = 1;
  } else if (!strcmp(str, "--number")) {
    opt->n = 1;
  } else if (!strcmp(str, "--squeeze-blank")) {
    opt->s = 1;
  } else {
    check = 0;
    printf("illegal option -- %c", str[1]);
  }
  return check;
}

int macOpt(char *str, option_t *opt) {
  int check = 1;
  for (size_t i = 1; i < strlen(str); i++) {
    if (str[i] == 'b') {
      opt->b = 1;
    } else if (str[i] == 'e') {
      opt->v = 1;
      opt->E = 1;
    } else if (str[i] == 'n') {
      opt->n = 1;
    } else if (str[i] == 's') {
      opt->s = 1;
    } else if (str[i] == 't') {
      opt->v = 1;
      opt->T = 1;
    } else if (str[i] == 'E') {
      opt->E = 1;
    } else if (str[i] == 'v') {
      opt->v = 1;
    } else if (str[i] == 'T') {
      opt->T = 1;
    } else {
      printf(
          "./s21_cat: illegal option -- %c\nusage: cat [-benstuv] [file ...]",
          str[i]);
      check = 0;
      break;
    }
  }
  return check;
}

void bufInit(buffer_t *buf) {
  buf->file_count = 0;
  buf->num_non_emp_line = 1;
  buf->num_line = 1;
  buf->pre = 10;
  buf->pre_pre = 10;
  buf->start_line_flag = 1;
  buf->is_spec = 0;
  buf->emp = 0;
}

char **memoryStrArr() {
  char **arr = (char **)calloc(SIZE, sizeof(char *));
  for (int i = 0; i < SIZE; i++) arr[i] = (char *)calloc(DIZE, sizeof(char));
  return arr;
}

void freeStrArr(char **arr) {
  for (int i = 0; i < SIZE; i++) free(arr[i]);
  free(arr);
}

void fileErrPrint(char *command, int opt, char *fileName) {
  if (opt == 0) {
    printf("%s: %s: No such file or directory\n", command, fileName);
  } else if (opt == -1) {
    printf("\nError closing file\n");
  }
}
