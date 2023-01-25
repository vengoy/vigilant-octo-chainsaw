#include "s21_string.h"

void *s21_to_upper(const char *str) {
    char *str_copy = S21_NULL;

    if (str != S21_NULL) {
        s21_size_t len = s21_strlen(str);

        str_copy = (char *)malloc(sizeof(char) * (len + 1));

        if (str_copy) {
            for (s21_size_t i = 0; i <= len; i++) {
                if (str[i] >= 'a' && str[i] <= 'z') {
                    str_copy[i] = (str[i] - 'a') + 'A';
                } else {
                    str_copy[i] = str[i];
                }
            }
            str_copy[len] = '\0';
        }
    }

    return str_copy;
}

void *s21_to_lower(const char *str) {
    char *str_copy = S21_NULL;

    if (str != S21_NULL) {
        s21_size_t len = s21_strlen(str);

        str_copy = (char *)malloc(sizeof(char) * (len + 1));

        if (str_copy) {
            for (s21_size_t i = 0; i <= len; i++) {
                if (str[i] >= 'A' && str[i] <= 'Z') {
                    str_copy[i] = (str[i] - 'A') + 'a';
                } else {
                    str_copy[i] = str[i];
                }
            }
            str_copy[len] = '\0';
        }
    }

    return str_copy;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char *res = S21_NULL;

    if (src != S21_NULL && str != S21_NULL) {
        s21_size_t src_len = s21_strlen(src);
        s21_size_t str_len = s21_strlen(str);
        s21_size_t new_len = src_len + str_len;

        if (str_len >= start_index) {
            res = (char *)malloc(sizeof(char) * new_len + 1);
        }

        if (res) {
            for (s21_size_t i = 0, j = 0, m = 0; i < new_len; i++) {
                if (i >= start_index && j < src_len) {
                    res[i] = src[j];
                    j++;
                } else {
                    res[i] = str[m];
                    m++;
                }
            }
            res[new_len] = '\0';
        }
    }

    return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
    char *res = S21_NULL;

    if (src) {
        if (trim_chars && *trim_chars) {
            s21_size_t len = s21_strlen(src);
            s21_size_t chars_len = s21_strlen(trim_chars);

            s21_trim_left(&src, trim_chars, &len, chars_len);
            if (len)
                s21_trim_right(&src, trim_chars, &len, chars_len);

            res = (char *)malloc(sizeof(char) * (len + 1));

            if (res) {
                for (s21_size_t i = 0; i < len + 1; i++) {
                    if (i < len) {
                        res[i] = src[i];
                    } else {
                        res[i] = '\0';
                    }
                }
            }
        } else {
            res = s21_trim(src, " \t\n");
        }
    }

    return res;
}

void s21_trim_left(const char **src, const char *trim_chars,
                   s21_size_t *src_len, const s21_size_t trim_chars_len) {
    s21_size_t m = 0;

    while (src && m != trim_chars_len) {
        if ((**src) == trim_chars[m]) {
            (*src)++;
            (*src_len) -= 1;
            m = 0;
            continue;
        }
        m++;
    }
}

void s21_trim_right(const char **src, const char *trim_chars,
                    s21_size_t *src_len, const s21_size_t trim_chars_len) {
    s21_size_t m = 0;
    s21_size_t i = (*src_len) - 1;

    while (src && m != trim_chars_len) {
        if ((*src)[i] == trim_chars[m]) {
            i--;
            (*src_len)--;
            m = 0;
            continue;
        }

        m++;
    }
}
