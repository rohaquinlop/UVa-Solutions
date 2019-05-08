/*
*
* Problema UVA 11677 - Alarm Clock
*
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int h1, m1, h2, m2;
  int cTime1, cTime2; /* Suma de los minutos en total */
  int dif;

  while(scanf("%d %d %d %d\n", &h1, &m1, &h2, &m2) == 4 ){
    if (h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0){
      break;
    }else{
      cTime1 = (h1*60) + m1;
      cTime2 = (h2*60) + m2;

      if(cTime2 < cTime1){
        cTime2 += 24*60;
      }
      dif = cTime2 - cTime1;

      cout << dif << endl;

    }
  }

  return 0;
}
