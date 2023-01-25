#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_s21_abs) {
  ck_assert_int_eq(s21_abs(-26346), abs(-26346));
  ck_assert_int_eq(s21_abs(26346), abs(26346));
  ck_assert_int_eq(s21_abs(0), abs(0));
}
END_TEST

START_TEST(test_s21_fabs) {
  ck_assert_ldouble_eq(s21_fabs(-5), fabs(-5));
  ck_assert_ldouble_eq(s21_fabs(5), fabs(5));
  ck_assert_ldouble_eq(s21_fabs(-45.876), fabs(-45.876));
  ck_assert_ldouble_eq(s21_fabs(45.876), fabs(45.876));
  ck_assert_ldouble_nan(fabs(s21_nan));
  ck_assert_ldouble_nan(s21_fabs(s21_nan));
  double y1, y2, tol = 0.000001;
  for (int i = -18; i <= 18; i++) {
    y1 = fabs(i * s21_PI / 18.0);
    y2 = s21_fabs(i * s21_PI / 18.0);
    ck_assert_ldouble_eq_tol(y1, y2, tol);
  }
}
END_TEST

START_TEST(test_s21_floor) {
  ck_assert_ldouble_eq(s21_fabs(-5), fabs(-5));
  ck_assert_ldouble_eq(s21_fabs(5), fabs(5));
  ck_assert_ldouble_eq(s21_fabs(-45.876), fabs(-45.876));
  ck_assert_ldouble_eq(s21_fabs(45.876), fabs(45.876));
  ck_assert_ldouble_eq(s21_fabs(-1), fabs(-1));
  ck_assert_ldouble_eq_tol(s21_floor(0.000001), floorl(0.000001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(-0.000001), floorl(-0.000001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(0.999999), floorl(0.999999), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(-0.999999), floorl(-0.999999), 1e-6);
  double y1, y2, tol = 0.000001;
  for (int i = -18; i <= 18; i++) {
    y1 = floor(i * s21_PI / 18.0);
    y2 = s21_floor(i * s21_PI / 18.0);
    ck_assert_ldouble_eq_tol(y1, y2, tol);
  }
}
END_TEST

START_TEST(test_s21_sin) {
  ck_assert_ldouble_eq_tol(s21_sin(0.5), sin(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(25), sin(25), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(26), sin(26), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(22.5 / 360.0), sin(22.5 / 360.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(10.5 / 260.0), sin(10.5 / 260.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(5.7 / 180.0), sin(5.7 / 180.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-29), sin(-29), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-30), sin(-30), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(30), sin(30), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0.999999), sinl(0.999999), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-0.999999), sinl(-0.999999), 1e-6);
  double y1, y2, tol = 0.000001;
  for (int i = -18; i <= 18; i++) {
    y1 = sin(i * s21_PI / 18.0);
    y2 = s21_sin(i * s21_PI / 18.0);
    ck_assert_ldouble_eq_tol(y1, y2, tol);
    ck_assert_ldouble_nan(s21_sin(0.0 / 0.0));
  }
}
END_TEST

START_TEST(test_s21_ceil) {
  ck_assert_ldouble_eq(s21_ceil(45.876), ceil(45.876));
  ck_assert_ldouble_eq(s21_ceil(-45.876), ceil(-45.876));
  ck_assert_ldouble_eq(s21_ceil(5.143), ceil(5.143));
  ck_assert_ldouble_eq(s21_ceil(5), ceil(5));
  ck_assert_ldouble_eq_tol(s21_ceil(0.000001), ceill(0.000001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.000001), ceill(-0.000001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(0.999999), ceill(0.999999), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.999999), ceill(-0.999999), 1e-6);
  double y1, y2, tol = 0.000001;
  for (int i = -18; i <= 18; i++) {
    y1 = ceil(i * s21_PI / 18.0);
    y2 = s21_ceil(i * s21_PI / 18.0);
    ck_assert_ldouble_eq_tol(y1, y2, tol);
    ck_assert_ldouble_nan(ceil(s21_nan));
    ck_assert_ldouble_nan(s21_ceil(s21_nan));
    y1 = ceil(0.0);
    y2 = s21_ceil(0.0);
    ck_assert_ldouble_eq_tol(y1, y2, tol);
  }
}
END_TEST

START_TEST(test_s21_exp) {
  ck_assert_ldouble_eq_tol(s21_exp(5), exp(5), 1e-06);
  ck_assert_ldouble_eq_tol(s21_exp(1), expl(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-1), exp(-1), 1e-06);
  ck_assert_ldouble_eq_tol(s21_exp(-6), exp(-6), 1e-06);
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), 1e-06);
  ck_assert_ldouble_eq_tol(s21_exp(0), expl(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(0.999999), expl(0.999999), 1e-6);
  ck_assert_ldouble_eq(s21_exp(999999999999999999999999.9),
                       expl(999999999999999999999999.9));
  double y1, y2, tol = 0.000001;
  for (int i = -18; i <= 18; i++) {
    y1 = exp(i * s21_PI / 18.0);
    y2 = s21_exp(i * s21_PI / 18.0);
    ck_assert_ldouble_eq_tol(y1, y2, tol);
    ck_assert_ldouble_nan(exp(s21_nan));
    ck_assert_ldouble_nan(s21_exp(s21_nan));
  }
}
END_TEST

START_TEST(test_s21_fmod) {
  ck_assert_ldouble_eq(s21_fmod(2, 5), fmod(2, 5));
  ck_assert_ldouble_eq(s21_fmod(2, 100), fmod(2, 100));
  ck_assert_ldouble_eq(s21_fmod(1, 100), fmod(1, 100));
  ck_assert_ldouble_eq(s21_fmod(7, 55), fmod(7, 55));
  ck_assert_ldouble_eq(s21_fmod(10.567, 4), fmod(10.567, 4));
  ck_assert_ldouble_eq(s21_fmod(10, 4), fmod(10, 4));
  ck_assert_ldouble_eq(s21_fmod(100, 2), fmod(100, 2));
  ck_assert_ldouble_nan(s21_fmod(0, 0));
  ck_assert_ldouble_eq_tol(s21_fmod(1, 1), fmodl(1, 1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(555.555, -2123.45),
                           fmodl(555.555, -2123.45), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(0.999999, 0.999999),
                           fmodl(0.999999, 0.999999), 1e-6);
  double y1, y2, tol = 0.000001;
  for (int i = -18; i <= 18 && i != 0; i++) {
    for (int j = 18; j >= -18 && j != 0; j--) {
      y1 = fmod(i * s21_PI / 18.0, j);
      y2 = s21_fmod(i * s21_PI / 18.0, j);
      ck_assert_ldouble_eq_tol(y1, y2, tol);
      ck_assert_ldouble_nan(fmod(s21_nan, s21_nan));
      ck_assert_ldouble_nan(s21_fmod(s21_nan, s21_nan));
    }
  }
}
END_TEST

START_TEST(test_s21_log) {
  ck_assert_ldouble_eq_tol(s21_log(5), log(5), 1e-06);
  ck_assert_ldouble_eq_tol(s21_log(3), log(3), 1e-06);
  ck_assert_ldouble_eq_tol(s21_log(7), log(7), 1e-06);
  ck_assert_ldouble_eq_tol(s21_log(125), log(125), 1e-06);
  ck_assert_int_eq(isnan(s21_log(-125)), 1);
  ck_assert_int_eq(isinf(s21_log(0) * (-1)), 1);
  ck_assert_ldouble_eq_tol(s21_log(45.876), log(45.876), 1e-06);
  ck_assert_int_eq(isnan(s21_log(-45.876)), 1);
  ck_assert_ldouble_eq_tol(s21_log(0.001), logl(0.001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(0.999999), logl(0.999999), 1e-6);
  ck_assert_int_eq(isnan(s21_log(-1)), 1);
  double y1, y2, tol = 0.000001;
}
END_TEST

START_TEST(test_s21_pow) {
    ck_assert_ldouble_eq_tol(s21_pow(0, 0.), pow(0, 0.), 1e-06);
    ck_assert_ldouble_eq_tol(s21_pow(2.6, 0.), pow(2.6, 0.), 1e-06);
    ck_assert_ldouble_eq_tol(s21_pow(1, 2.6), pow(1, 2.6), 1e-06);
    ck_assert_ldouble_eq_tol(s21_pow(0., 2.6), pow(0., 2.6), 1e-06);
    ck_assert_ldouble_eq_tol(s21_pow(2.6, 3.45), pow(2.6, 3.45), 1e-06);
    ck_assert_ldouble_eq(s21_pow(-2.6, -S21_INF), pow(-2.6, -S21_INF));
    ck_assert_ldouble_eq(s21_pow(-2.6, S21_INF), pow(-2.6, S21_INF));
    ck_assert_ldouble_eq(s21_pow(-1, S21_INF), pow(-1, S21_INF));
    ck_assert_ldouble_eq(s21_pow(-0.123456, S21_INF),
                         pow(-0.123456, S21_INF));
    ck_assert_int_eq(s21_pow(-2.6, 3.45) == s21_nan, pow(-2.6, 3.45) == s21_nan);
    ck_assert_ldouble_eq_tol(s21_pow(2, 3), pow(2, 3), 1e-06);
    ck_assert_ldouble_eq_tol(s21_pow(-2, 3), pow(-2, 3), 1e-06);
    ck_assert_ldouble_eq_tol(s21_pow(-2, -3), pow(-2, -3), 1e-06);
    ck_assert_ldouble_eq_tol(s21_pow(-2, 0), pow(-2, 0), 1e-06);
    ck_assert_ldouble_eq_tol(s21_pow(3.0, -14.0), pow(3.0, -14.0), 1e-06);
    ck_assert_ldouble_eq_tol(s21_pow(31.456, 0.3), pow(31.456, 0.3), 1e-06);
    ck_assert_ldouble_eq_tol(s21_pow(4.3, 4.3), pow(4.3, 4.3), 1e-06);
}
END_TEST

START_TEST(test_s21_sqrt) {
  ck_assert_ldouble_eq_tol(s21_sqrt(5), sqrt(5), 1e-06);
  ck_assert_ldouble_eq_tol(s21_sqrt(125), sqrt(125), 1e-06);
  ck_assert_ldouble_eq_tol(s21_sqrt(125), sqrt(125), 1e-06);
  ck_assert_ldouble_eq_tol(s21_sqrt(2.456), sqrt(2.456), 1e-06);
  ck_assert_ldouble_eq_tol(s21_sqrt(122.456), sqrt(122.456), 1e-06);
  ck_assert_int_eq(isnan(s21_sqrt(-125)), 1);
  ck_assert_ldouble_eq_tol(s21_sqrt(0.2147483647), sqrtl(0.2147483647), 1e-06);
  double y1, y2, tol = 0.000001;
  for (int i = -18; i < 0; i++) {
    y2 = s21_sqrt(i * s21_PI / 18.0);
    ck_assert_ldouble_nan(y2);
  }
  for (int i = 1; i <= 18; i++) {
    y1 = sqrt(i * s21_PI / 18.0);
    y2 = s21_sqrt(i * s21_PI / 18.0);
    ck_assert_ldouble_eq_tol(y1, y2, tol);
    ck_assert_ldouble_nan(sqrt(s21_nan));
    ck_assert_ldouble_nan(s21_sqrt(s21_nan));
  }
}
END_TEST

START_TEST(test_s21_cos) {
  ck_assert_ldouble_eq_tol(s21_cos(0.5), cos(0.5), 1e-5);
  ck_assert_ldouble_eq_tol(s21_cos(25), cos(25), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(26), cos(26), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(22.5 / 360.0), cos(22.5 / 360.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(10.5 / 260.0), cos(10.5 / 260.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(5.7 / 180.0), cos(5.7 / 180.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-29), cos(-29), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-30), cos(-30), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(30), cos(30), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), 1e-5);
  ck_assert_ldouble_eq_tol(s21_cos(0.999999), cosl(0.999999), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-0.999999), cosl(-0.999999), 1e-6);
  double y1, y2, tol = 0.000001;
  for (int i = -18; i <= 18; i++) {
    y1 = cos(i * s21_PI / 18.0);
    y2 = s21_cos(i * s21_PI / 18.0);
    ck_assert_ldouble_eq_tol(y1, y2, tol);
    ck_assert_ldouble_nan(s21_cos(S21_INF));
    ck_assert_ldouble_nan(s21_cos(0.0 / 0.0));
  }
}
END_TEST

START_TEST(test_s21_asin) {
  ck_assert_ldouble_eq_tol(s21_asin(0.5), asin(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);
  ck_assert_int_eq(isnan(s21_asin(26)), 1);
  ck_assert_ldouble_eq_tol(s21_asin(22.5 / 360.50), asin(22.5 / 360.50), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(10.5 / 260.2), asin(10.5 / 260.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(5.7 / 180.6), asin(5.7 / 180.6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-6);
  ck_assert_double_eq_tol(s21_asin(0.2147483647), asinl(0.2147483647), 1e-6);
  ck_assert_double_eq_tol(s21_asin(-0.2147483647), asinl(-0.2147483647), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.999999), asinl(0.999999), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0.999999), asinl(-0.999999), 1e-6);
  ck_assert_ldouble_nan(s21_asin(2));
  double y1, y2, tol = 0.000001;
  for (int i = -18; i < -5; i++) {
    y2 = s21_asin(i * s21_PI / 18.0);
    ck_assert_ldouble_nan(y2);
  }
  for (int i = -5; i < 6; i++) {
    y1 = asin(i * s21_PI / 18.0);
    y2 = s21_asin(i * s21_PI / 18.0);
    ck_assert_ldouble_eq_tol(y1, y2, tol);
  }
  ck_assert_ldouble_nan(asin(S21_INF));
  ck_assert_ldouble_nan(s21_asin(S21_INF));
  ck_assert_ldouble_nan(s21_asin(-7));
  ck_assert_ldouble_nan(s21_asin(7));
}
END_TEST

START_TEST(test_s21_acos) {
  ck_assert_ldouble_eq_tol(s21_acos(0.5), acos(0.5), 1e-5);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-6);
  ck_assert_int_eq(isnan(s21_acos(26)), 1);
  ck_assert_ldouble_eq_tol(s21_acos(22.5 / 360.50), acos(22.5 / 360.50), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(10.5 / 260.2), acos(10.5 / 260.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(5.7 / 180.6), acos(5.7 / 180.6), 1e-6);
  ck_assert_int_eq(isnan(s21_acos(-29)), 1);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-6);
  ck_assert_int_eq(isnan(s21_acos(-1.464)), 1);
  ck_assert_ldouble_eq_tol(s21_acos(0.2147483647), acosl(0.2147483647), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-0.2147483647), acosl(-0.2147483647), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.999999), acosl(0.999999), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-0.999999), acosl(-0.999999), 1e-6);
  double y1, y2, tol = 0.000001;
  for (int i = -18; i < -6; i++) {
    y1 = acos(i * s21_PI / 18.0);
    y2 = s21_acos(i * s21_PI / 18.0);
    ck_assert_ldouble_nan(y2);
  }
  for (int i = -5; i <= 5; i++) {
    y1 = acos(i * s21_PI / 18.0);
    y2 = s21_acos(i * s21_PI / 18.0);
    ck_assert_ldouble_eq_tol(y1, y2, tol);
    ck_assert_ldouble_nan(acos(s21_nan));
    ck_assert_ldouble_nan(s21_acos(s21_nan));
    ck_assert_ldouble_nan(s21_acos(-7));
    ck_assert_ldouble_nan(s21_acos(7));
  }
}
END_TEST

START_TEST(test_s21_tan) {
  ck_assert_ldouble_eq_tol(s21_tan(0.5), tan(0.5), 1e-5);
  ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(26), tan(26), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(22.5 / 360.50), tan(22.5 / 360.50), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(10.5 / 260.2), tan(10.5 / 260.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(5.7 / 180.6), tan(5.7 / 180.6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-29), tan(-29), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(55.5), tanl(55.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-55.5), tanl(-55.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0.999999), tanl(0.999999), 1e-6);
  double y1, y2, tol = 0.000001;
  for (int i = -18; i < -10; i++) {
    y1 = tan(i * s21_PI / 18.0);
    y2 = s21_tan(i * s21_PI / 18.0);
    ck_assert_ldouble_eq_tol(y1, y2, tol);
    ck_assert_ldouble_nan(tan(s21_nan));
    ck_assert_ldouble_nan(s21_tan(s21_nan));
  }
}
END_TEST

START_TEST(test_s21_atan) {
  ck_assert_ldouble_eq_tol(s21_atan(0.5), atan(0.5), 1e-5);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(26), atan(26), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(22.5 / 360.50), atan(22.5 / 360.50), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(10.5 / 260.2), atan(10.5 / 260.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(5.7 / 180.6), atan(5.7 / 180.6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-29), atan(-29), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(2147483647), atanl(2147483647), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-2147483647), atanl(-2147483647), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.999999), atanl(0.999999), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-0.999999), atanl(-0.999999), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(16), atan(16), 1e-6);
  double y1, y2, tol = 0.000001;
  for (int i = -18; i < 18; i++) {
    y1 = atan(i * s21_PI / 18.0);
    y2 = s21_atan(i * s21_PI / 18.0);
    ck_assert_ldouble_eq_tol(y1, y2, tol);
    ck_assert_ldouble_nan(atan(s21_nan));
    ck_assert_ldouble_nan(s21_atan(s21_nan));
  }
}
END_TEST

int main() {
  Suite *s = suite_create("s21_math");
  TCase *test_case = tcase_create("s21_math");
  SRunner *s_run = srunner_create(s);
  int result;
  suite_add_tcase(s, test_case);

  tcase_add_test(test_case, test_s21_abs);
  tcase_add_test(test_case, test_s21_fabs);
  tcase_add_test(test_case, test_s21_floor);
  tcase_add_test(test_case, test_s21_sin);
  tcase_add_test(test_case, test_s21_ceil);
  tcase_add_test(test_case, test_s21_exp);
  tcase_add_test(test_case, test_s21_fmod);
  tcase_add_test(test_case, test_s21_log);
  tcase_add_test(test_case, test_s21_pow);
  tcase_add_test(test_case, test_s21_sqrt);
  tcase_add_test(test_case, test_s21_cos);
  tcase_add_test(test_case, test_s21_asin);
  tcase_add_test(test_case, test_s21_acos);
  tcase_add_test(test_case, test_s21_tan);
  tcase_add_test(test_case, test_s21_atan);

  srunner_run_all(s_run, CK_VERBOSE);
  result = srunner_ntests_failed(s_run);
  srunner_free(s_run);
  return result == 0 ? 0 : 1;
}
