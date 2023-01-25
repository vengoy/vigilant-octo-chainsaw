#include "s21_math.h"

long double s21_fabs(double x) {
    return (x < 0) ? -x : x;
}

int s21_abs(int x) {
    return x < 0 ? -x : x;
}


long double s21_atan(double x) {
  long double result = 0;
  int f_minus = 1;
  if (x < 0) {
    x *= (-1);
    f_minus = -1;
  }
  if (x < 0.9) {
    for (int k = 0; k < 100; k++) {
      long double current = 1;
      int j;
      for (j = 1; j <= 2 * k + 1; ++j) {
        current *= x;
      }
      if (j != 0) {
        current /= (j - 1);
      }
      result += s21_pow(-1, k) * current;
    }
  } else if (x > 1) {
    result = (s21_PI / 2) - s21_atan(1 / x);
  } else {
    result = s21_asin(x / s21_sqrt(1 + x * x));
  }
  return f_minus * result;
}



long double s21_asin(double x) {  // 3
  double tmp = x, result = x;
  if (x < -1 || x > 1) {
    result = 0.0 / 0.0;
  } else if (x == -1 || x == 1) {
    result = s21_PI / 2 * x;
  } else {
    for (long double num = 1; s21_fabs(tmp) > s21_eps; num++) {
      tmp *= ((x * x) * (2 * num - 1) * (2 * num - 1)) /
             ((2 * num) * (2 * num + 1));
      result += tmp;
    }
  }
  return result;
}

long double s21_acos(double x) {
    if (x <= 1 && x >= -1) {
        x = s21_PI / 2. - s21_asin(x);
    } else {
        x = s21_nan;
    }
    return x;  // Nice, good job
}


long double s21_ceil(double x) {  // 5
    long long int buf = (long long int)x;
    double result = (double)buf;
    if (x >= (double)LLONG_MAX || x <= (double)LLONG_MIN || x != x) {  // Если x > 16 зн. или == inf/-inf/nan,
        result = x;
    } else if (x > 0.0 && x != result) {
        result += 1;
    } else if (x < 0.0 && result == 0.0) {
        result = -0.0;
    }
    return (long double)result;
}


long double s21_floor(double x) {
    long double xcopy = x < 0 ? x *-1 : x;
    unsigned int zeros = 0;
    long double n = 1;
    for ( n = 1 ; xcopy > n * 10 ; n *= 10 , ++zeros ) {}
    for (xcopy -= n ; zeros != -(unsigned int)1 ; xcopy -= n )
        if ( xcopy < 0 ) {
            xcopy += n;
            n /= 10;
            --zeros;
        }
    xcopy += n;
    return x < 0 ? ( xcopy == 0 ? x : x - (1-xcopy) ) : (x-xcopy);
}

long double s21_fmod(double x, double y) {
    if (y == 0) {
        x = 0.0 / 0.0;
    } else {
        x = x - (long double)((int)(x / y)) * y;
    }
    return x;
}


long double s21_sin(double x) {
    if (is_nan(x) || !is_finite(x))
           return s21_nan;
    x = s21_fmod(x, 2 * s21_PI);
    int counter = 1;

    if (x > (s21_PI / 2.0) && x <= s21_PI) {
        x = s21_PI - x;
    } else if (x > s21_PI && x <= s21_PI * 3.0 / 2.0) {
        x = (x - s21_PI);
        counter = -counter;
    } else if (x > (s21_PI * 3.0) / 2.0 && x <= 2.0 * s21_PI) {
        x = 2 * s21_PI - x;
        counter = -counter;
    }
    long double sum = (long double)x;
    long double tailor = (long double)x;

    for (int p = 1; s21_fabs(tailor / sum) > 1e-15; p++) {
        tailor = (-tailor * x * x) / ((2.0 * p + 1) * (2.0 * p));
        sum += tailor;
    }
    return sum * counter;
}

long double s21_cos(double x) {
    if (is_nan(x) || !is_finite(x))
           return s21_nan;
    int counter = 1;
    x = s21_fmod(x, 2 * s21_PI);

    if (x > (s21_PI / 2.0) && x <= s21_PI) {
        x = s21_PI - x;
        counter = -counter;
    } else if (x > s21_PI && x <= s21_PI * 3.0 / 2.0) {
        x -= s21_PI;
        counter = -counter;
    } else if (x > (s21_PI * 3.0) / 2.0 && x <= 2.0 * s21_PI) {
        x = 2 * s21_PI - x;
    }
    long double sum = 1.0;
    long double tailor = 1.0;
    for (int p = 1; s21_fabs(tailor / sum) > 1e-15; p++) {
        tailor = (-tailor * x * x) / ((2.0 * p - 1) * (2.0 * p));
        sum += tailor;
    }
    return sum * counter;
}




long double s21_log(double x) {
    long double sign = 1, degree = 0, count = 2, result, temp;
    x < 0 ? (x *= -1, sign *= -1) : (x *= 1, sign *= 1);
    while ((x >= 10) || (x < 1 && x > 0))
        x<1 && x> 0 ? (x *= 10, degree -= 1) : (x *= 0.1, degree += 1);
    x = sign * x / 10;
    if (x < 0) {
        result = -0.0 / 0.0;
    } else if (x == 0) {
        result = -1.0 / 0.0;
    } else {
        x--;
        result = x;
        temp = x;
        while (s21_fabs(result) > s21_eps) {
            result *= -x * (count - 1) / count;
            count += 1;
            temp += result;
        }
        result = temp + (degree + 1) * 2.30258509299404590109;
    }
    return result;
}

long double s21_pow(double base, double exp) {
    long double number;
    if (base < 0) {
        if ((long int)exp == exp) {
            if (exp > 0) {
                number = base;
                for (long int i = 0; i < (long int)exp - 1; i++) number *= base;

            } else if (exp == 0) {
                number = 1;
            } else {
                number = 1 / base;
                for (long int i = 0; i < (long int)exp * (-1) - 1; i++) {
                    number /= base;
                }
            }
        } else {
            if (exp == -S21_INF || exp == S21_INF) {
                if (base * (-1) < 1) {
                    number = 0;
                } else if (base * (-1) == 1) {
                    number = 1;
                } else {
                    if (exp == -S21_INF) {
                        number = 0;
                    } else {
                        number = S21_INF;
                    }
                }
            } else {
                number = -s21_nan;
            }
        }
    } else if (base == 0) {
        if (exp == 0)
            number = 1;
        else
            number = 0;
    } else if (base == 1) {
        number = 1;
    } else {
        if ((long int)exp == exp) {
            if (exp > 0) {
                number = base;
                for (long int i = 0; i < (long int)exp - 1; i++) {
                    number *= base;
                }
            } else if (exp == 0) {
                number = 1;
            } else {
                number = 1 / base;
                for (long int i = 0; i < (long int)exp * (-1) - 1; i++) {
                    number /= base;
                }
            }
        } else {
            number = s21_exp(exp * (double)s21_log(base));
        }
    }
    return number;
}



long double s21_sqrt(double x) {
    long double start = 0, end = x;
    long double average;

    long double root;

    if (x >= 0) {
            while (start <= end) {
                average = (start + end) / 2;

                if (average * average == x) {
                    root = average;
                    break;
                }

                if (average * average < x) {
                    root = start;
                    start = average + 1;
                } else {
                    end = average - 1;
                }
            }
            float increment = 0.1;
            for (int i = 0; i < 7; i++) {
                while (root * root <= x) {
                    root += increment;
                }

                root = root - increment;
                increment = increment / 10;
            }
        } else {
            root = 0.0 / 0.0;
        }
    return root;
}

long double s21_tan(double x) {
    return (long double)(s21_sin(x) / s21_cos(x));
}

long double s21_exp(double x) {
    long double result = 1, temp = 1, i = 1;
    int flag = 0;
    if (x < 0) {
        x *= -1;
        flag = 1;
    }
    while (s21_fabs(result) > s21_eps) {
        result *= x / i;
        i += 1;
        temp += result;
        if (temp > s21_MAX_double) {
            temp = 1.0 / 0.0;
            break;
        }
    }
    (temp = flag == 1 ? (temp > s21_MAX_double ? 0 : 1. / temp) : temp);
    return temp > s21_MAX_double ? 1.0 / 0.0 : temp;
}
