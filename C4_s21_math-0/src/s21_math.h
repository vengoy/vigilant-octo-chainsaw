#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define s21_PI 3.1415926535
#define s21_eps 1e-17
#define s21_nan 0.0 / 0.0
#define S21_INF 1.0 / 0.0
#define is_nan(x) __builtin_isnan(x)
#define is_inf(x) __builtin_isinf(x)
#define is_finite(x) __builtin_isfinite(x)
#define s21_MAX_double 1.7976931348623158e308
#include <limits.h>

long double s21_cos(double x);

long double s21_exp(double x);

int s21_abs(int x);

long double s21_ceil(double x);

long double s21_atan(double x);

long double s21_asin(double x);

long double s21_acos(double x);

long double s21_fabs(double x);

long double s21_floor(double x);

long double s21_fmod(double x, double y);

long double s21_log(double x);

long double s21_pow(double base, double exp);

long double s21_sin(double x);

long double s21_sqrt(double x);

long double s21_tan(double x);

#endif  //  SRC_S21_MATH_H_
