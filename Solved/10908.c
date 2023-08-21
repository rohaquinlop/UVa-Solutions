/*
 *
 * Problema UVA 10908 - Largest Square
 *
 */

#include <stdio.h>

char grid[100][100];

int solve(int M, int N, int r, int c) {
  int ans = 1, i, flag = 1;

  while ((r - ans) >= 0 && (r + ans < M) && (c - ans) >= 0 && (c + ans) < N &&
         flag) {
    for (i = r - ans; i <= r + ans && flag; i++) {
      if (grid[i][c - ans] != grid[i][c + ans] ||
          grid[i][c - ans] != grid[r][c])
        flag = 0;
    }

    for (i = c - ans; i <= c + ans && flag; i++) {
      if (grid[r - ans][i] != grid[r + ans][i] ||
          grid[r - ans][i] != grid[r][c])
        flag = 0;
    }

    if (flag) ans++;
  }

  return 1 + 2 * (ans - 1);
}

int main() {
  int T, M, N, Q;
  int i, r, c;

  scanf("%d\n", &T);

  while (T--) {
    scanf("%d %d %d\n", &M, &N, &Q);

    for (i = 0; i < M; i++) {
      scanf("%s\n", grid[i]);
    }

    printf("%d %d %d\n", M, N, Q);

    while (Q--) {
      scanf("%d %d\n", &r, &c);
      printf("%d\n", solve(M, N, r, c));
    }
  }

  return 0;
}