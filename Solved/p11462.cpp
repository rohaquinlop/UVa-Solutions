/*
*
* Problema UVA 11462 - Age Sort
*
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n, i, aux;

  while( scanf("%d", &n) == 1 ){
    if( n == 0){
      break;
    }else{
      vector<int> nums;


      for(i = 0; i < n; i++){
        scanf("%d", &aux);
        nums.push_back(aux);
      }
      sort( nums.begin(), nums.end() );

      for(i = 0; i < n; i++){
        printf("%d", nums[i]);
        if( i < n-1 )
          printf(" ");
      }
      printf("\n");

    }
  }


  return 0;
}
