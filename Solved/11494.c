/*
 *
 * Problema UVA 11494 - Queen
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
  int x1, y1, x2, y2;
  int dx, dy;

  while (scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2) && x1 + y1 + x2 + y2 != 0) {
    dx = abs(x1 - x2);
    dy = abs(y1 - y2);

    if (dx + dy == 0) {
      printf("0\n");
    } else if ((dx == dy) || (x1 == x2) || (y1 == y2)) {
      printf("1\n");
    } else {
      printf("2\n");
    }
  }

  return 0;
}