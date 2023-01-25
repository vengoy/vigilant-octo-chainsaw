#include "s21_string.h"
static int s21_includes_exponent(const char *buffer);
static long double s21_atof(const char *buffer);
static long double s21_apply_exponent(long double res, const char *buffer);

long double s21_strtold(const char *buffer) {
    long double res;
    res = s21_atof(buffer);
    if (s21_includes_exponent(buffer)) {
        res = s21_apply_exponent(res, buffer);
    }
    return res;
}

static long double s21_apply_exponent(long double res, const char *buffer) {
    char sign = '+';
    int expon = 0;
    for (char *p = (char *)buffer; *p; p++) {
        if (*p == 'e' || *p == 'E') {
            sign = *(p + 1);
            expon = s21_atoi(p + 2);
        }
    }

    while (expon) {
        if (sign == '-') {
            res /= 10.0;
        } else {
            res *= 10.0;
        }
        expon--;
    }

    return res;
}

static int s21_includes_exponent(const char *buffer) {
    int res = 0;

    for (char *p = (char *)buffer; *p; p++) {
        if (s21_strspn(p, "eE")) {
            res = 1;
            break;
        }
    }

    return res;
}

static long double s21_atof(const char *buffer) {
    long double frac = 0.0;
    char *p = (char *)buffer;
    int minus_flag = (*p == '-');
    long double res = s21_atoi(p);

    while (s21_isdigit(*p))
        p++;

    if (*p == '.') {
        p++;
        int trailing_zeros = s21_strspn(p, "0");
        frac = s21_atoi(p);
        int tmp = (int)frac;
        while (tmp) {
            frac /= 10.0;
            tmp /= 10;
        }
        while (trailing_zeros) {
            frac /= 10.0;
            trailing_zeros--;
        }
    }

    res += frac;

    return minus_flag ? -res : res;
}
