#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int main() {
  int t, i;
  char s[1000], c;
  int freq[26], most_freq;

  scanf("%d\n", &t);

  while (t--) {
    fgets(s, 1000, stdin);

    most_freq = 0;
    for (i = 0; i < 26; i++) freq[i] = 0;

    for (i = 0; i < strlen(s); i++) {
      c = s[i];

      if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        if ((c >= 'A' && c <= 'Z')) c = 'a' + (c - 'A');
        most_freq = max(++freq[c - 'a'], most_freq);
      }
    }

    for (c = 'a'; c <= 'z'; c++) {
      if (freq[c - 'a'] == most_freq) printf("%c", c);
    }
    printf("\n");
  }

  return 0;
}