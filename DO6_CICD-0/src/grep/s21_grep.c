#include "s21_grep.h"

int main(int argc, char *argv[]) {
  parse_input(argc, argv);
  return 0;
}

void parse_input(int argc, char *argv[]) {
  unsigned int flag = 0;
  flags q = {0};
  int i = 1;
  while (i < argc && q.error == 0) {
    if (argv[i][0] == '-') {
      parse_flags(argv[i], &q, &i, argv);
    } else {
      q.f_cnt++;
    }
    i++;
  }
  if (q.e == 0 && q.f == 0) q.f_cnt--;
  i = 1;
  while (i < argc && q.error == 0) {
    if (argv[i][0] == '-') {
      if (strstr(argv[i], "e") || strstr(argv[i], "f")) {
        i++;
      }
    } else if (q.e == 0 && q.f == 0 && flag == 0) {
      e_str(argv[i], &q);
      flag = 1;
    } else {
      formated_print(argv[i], &q);
    }
    if (q.error == 0) {
      i++;
    }
  }
  if (q.temp) free(q.temp);

  if (q.error > 0) {
    if (q.error == 1 && argv[i][0] == '-') {
      fprintf(stderr, "grep: illegal option -%c\n", q.str_error);
      fprintf(stderr, "usage: grep [-eivclnhsfo] [pattern] [file ...]\n");
    } else {
      fprintf(stderr, "usage: grep [-eivclnhsfo] [pattern] [file ...]\n");
    }
  }
}

void parse_flags(char *str, flags *q, int *n, char *argv[]) {
  while (*(++str) != '\0') {
    switch (*str) {
      case 'e':
        e_str(argv[*n + 1], q);
        *n += 1;
        q->e = 1;
        break;
      case 'f':
        f_str(argv[*n + 1], q);
        *n += 1;
        q->f = 1;
        break;
      case 'i':
        q->i = 1;
        break;
      case 'l':
        q->l = 1;
        break;
      case 'v':
        q->v = 1;
        break;
      case 'c':
        q->c = 1;
        break;
      case 'n':
        q->n = 1;
        break;
      case 'h':
        q->h = 1;
        break;
      case 's':
        q->s = 1;
        break;
      case 'o':
        q->o = 1;
        break;
      default:
        q->error = 1;
        q->str_error = *str;
    }
  }
}

void e_str(char *pt, flags *q) {
  char *p = NULL;
  int str_temp = 0;

  regex_t reg;
  int cflag = REG_EXTENDED | REG_NEWLINE;
  if (regcomp(&reg, pt, cflag)) {
    pt = NULL;
  } else {
    regfree(&reg);
  }

  if (q->temp) {
    str_temp = strlen(q->temp);
  }
  if (pt != NULL) {
    p = calloc((strlen(pt) + str_temp + 50), sizeof(char));
  }
  if (p) {
    if (q->temp) {
      sprintf(p, "%s|%s", q->temp, pt);
      free(q->temp);
    } else {
      sprintf(p, "%s", pt);
    }
    q->temp = p;
  }
}

void f_str(char *name, flags *q) {
  FILE *fp = NULL;
  fp = fopen(name, "r");

  if (fp == NULL) {
    if (q->s != 1) {
      fprintf(stderr, "grep: %s: No such file or directory\n", name);
    }
  } else {
    char line_buff[1024] = "";
    int ch;
    ch = fgetc(fp);
    int cnt = 0;
    while (1) {
      if ((cnt == sizeof(line_buff) - 1) || ch == '\n' || ch == EOF) {
        line_buff[cnt] = '\0';
        if (strlen(line_buff)) {
          e_str(line_buff, q);
        }
        cnt = 0;
        if (ch == EOF) break;
      } else {
        line_buff[cnt] = (char)ch;
        cnt++;
      }
      ch = fgetc(fp);
    }
    fclose(fp);
  }
}

void formated_print(char *str, flags *q) {
  FILE *fp = NULL;
  fp = fopen(str, "r");

  if (fp == NULL) {
    if (q->s != 1) {
      fprintf(stderr, "grep: %s: No such file or directory\n", str);
    }
  } else {
    int cflags = REG_EXTENDED | REG_NEWLINE;

    if (q->i == 1) {
      cflags |= REG_ICASE;
    }

    regex_t reg;

    if (q->temp) {
      regcomp(&reg, q->temp, cflags);

      int line_cnt = 0;
      file_process(str, fp, &reg, &line_cnt, q);

      flag_lc(str, line_cnt, q);
      regfree(&reg);
    }
    fclose(fp);
  }
}

void file_process(char const *str, FILE *fp, regex_t *reg, int *line_cnt,
                  flags *q) {
  char line_buff[1024] = "";
  char line_buff2[1024] = "";
  int ch;
  int cnt = 0;
  int file_line_cnt = 0;
  regmatch_t regmatch[1];
  ch = fgetc(fp);
  while (1) {
    if ((cnt == sizeof(line_buff) - 1) || ch == '\n' || ch == EOF) {
      if (ch == '\n') {
        line_buff[cnt++] = '\n';
        file_line_cnt++;
      }
      line_buff[cnt] = '\0';
      size_t len_buff = strlen(line_buff);
      if (len_buff) {
        int match_res = regexec(reg, line_buff, 1, regmatch, 0);
        if (ch == EOF) {
          line_buff[cnt++] = '\n';
          line_buff[cnt] = '\0';
        }

        if (match_res == 0 && q->v == 0) {
          if (q->o == 1) {
            unsigned int exit_fl = 0;
            size_t offset = 0;
            do {
              size_t buff_len = regmatch->rm_eo - regmatch->rm_so;
              strncat(line_buff2, line_buff + offset + regmatch->rm_so,
                      buff_len);
              strcat(line_buff2, "\n");

              offset += regmatch->rm_eo;

              if (regmatch->rm_so == regmatch->rm_eo) {
                offset += 1;
              }

              if (offset > len_buff) {
                exit_fl = 1;
              }
            } while (regexec(reg, line_buff + offset, 1, regmatch, 0) !=
                         REG_NOMATCH ||
                     exit_fl == 1);

            strcpy(line_buff, line_buff2);
            strcpy(line_buff2, "");
          }

          if (q->l == 1 && *line_cnt == 0)
            *line_cnt = 1;
          else if (q->l == 0)
            *line_cnt += 1;

          find_print(str, line_buff, file_line_cnt, q);

        } else if (match_res == REG_NOMATCH && q->v == 1) {
          if (q->l == 1 && *line_cnt == 0)
            *line_cnt = 1;
          else if (q->l == 0)
            *line_cnt += 1;

          find_print(str, line_buff, file_line_cnt, q);
        }
      }
      cnt = 0;
      if (ch == EOF) break;
    } else {
      line_buff[cnt] = (char)ch;
      cnt++;
    }
    ch = fgetc(fp);
  }
}

void flag_lc(char *str, int line_cnt, flags *q) {
#if defined(__APPLE__) || (__MACH__)
  if (q->c == 1) {
#else
  if (q->c == 1 && q->l == 0) {
#endif
    if (q->f_cnt == 1) {
      printf("%d\n", line_cnt);
    } else {
      if (q->h == 0) {
        printf("%s:%d\n", str, line_cnt);
      } else {
        printf("%d\n", line_cnt);
      }
    }
  }
  if (q->l == 1 && line_cnt > 0) {
    printf("%s\n", str);
  }
}

void find_print(char const *name, char *str, int cnt, flags *q) {
  if (q->c == 0 && q->l == 0) {
    if (q->f_cnt > 1 && q->n == 1) {
      if (q->h == 0)
        printf("%s:%d:%s", name, cnt, str);
      else
        printf("%d:%s", cnt, str);
    } else if (q->f_cnt > 1 && q->n == 0) {
      if (q->h == 0)
        printf("%s:%s", name, str);
      else
        printf("%s", str);
    } else if (q->f_cnt == 1 && q->n == 1) {
      printf("%d:%s", cnt, str);
    } else if (q->f_cnt == 1 && q->n == 0) {
      printf("%s", str);
    }
  }
}
