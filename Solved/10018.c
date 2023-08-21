/*
 *
 * Problema UVA 10018 - Reverse and Add
 *
 */

#include <stdio.h>

long int reverse_num(long int p) {
  long int ans = 0;

  while (p > 0) {
    ans *= 10;
    ans += p % 10;
    p /= 10;
  }

  return ans;
}

int is_palindrome(long int p) {
  long int p_prime = reverse_num(p);

  return p_prime == p;
}

int main() {
  int N, cnt;
  long int p, p_prime;

  scanf("%d\n", &N);

  while (N--) {
    scanf("%li\n", &p);
    cnt = 1;

    p += reverse_num(p);

    while (!is_palindrome(p)) {
      p_prime = reverse_num(p);
      p += p_prime;
      cnt++;
    }

    printf("%d %ld\n", cnt, p);
  }

  return 0;
}