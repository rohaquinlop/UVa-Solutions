/*
 *
 * Problema UVA 11715 - Car
 *
 */

#include <math.h>
#include <stdio.h>

int main() {
  int n, c = 0;
  double u, v, t, s, a;

  while (scanf("%d", &n) && n != 0) {
    printf("Case %d: ", ++c);
    if (n == 1) {
      scanf(" %lf %lf %lf\n", &u, &v, &t);

      a = (v - u) / t;
      s = (u * t) + (0.5 * a * t * t);
      printf("%.3lf %.3lf\n", s, a);
    } else if (n == 2) {
      scanf(" %lf %lf %lf\n", &u, &v, &a);

      t = (v - u) / a;
      s = (u * t) + (0.5 * a * t * t);
      printf("%.3lf %.3lf\n", s, t);
    } else if (n == 3) {
      scanf(" %lf %lf %lf\n", &u, &a, &s);

      v = sqrt(2 * a * s + u * u);
      t = (v - u) / a;

      printf("%.3lf %.3lf\n", v, t);
    } else {
      scanf(" %lf %lf %lf\n", &v, &a, &s);

      u = sqrt(v * v - 2 * a * s);
      t = (v - u) / a;

      printf("%.3lf %.3lf\n", u, t);
    }
  }

  return 0;
}
