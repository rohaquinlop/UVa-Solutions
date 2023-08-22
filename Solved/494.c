#include <stdio.h>
#include <stdlib.h> /*fgets*/
#include <string.h> /*strlen*/

/*
ANSI C no tiene comentarios de una sola línea
// -> No está disponible en ANSI C pero si está disponible para C++
*/

int main() {
  char str[1000];
  int ans, i, flag;

  /*
  fgets(str, 1000, stdin) -> 0 | NULL
  scanf("%[^\n]%*c\n", str) -> EOF ||| https://stackoverflow.com/a/6282236
  */

  while (scanf("%[^\n]%*c\n", str) != EOF) {
    ans = 0;
    flag = 0;

    for (i = 0; i < strlen(str); i++) {
      if ((str[i] >= 'A' && str[i] <= 'Z') ||
          (str[i] >= 'a' && str[i] <= 'z')) {
        if (!flag) {
          ans++;
          flag = 1;
        }
      } else
        flag = 0;
    }

    printf("%d\n", ans);
  }
  return 0;
}