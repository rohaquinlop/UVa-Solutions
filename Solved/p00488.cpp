/*
 *
 * Problema UVa 488 - Triangle Wave
 *
*/
#include<cstdio>
#include<iostream>

using namespace std;

int main(){
    int cases, frec, amp;
    int i, j, c = 0;

    scanf("%d", &cases);

    while(cases--){
        c++;
        if( c > 1 ){
            printf("\n");
        }
        scanf("%d", &frec);
        scanf("%d", &amp);

        while(amp--){
            for(i = 0; i < frec; i++){
                for(j = 0; j <= i; j++){
                    printf("%d", i+1);
                }
                printf("\n");
            }
            for(i = frec-1; i > 0; i--){
                for(j = 0; j < i; j++){
                    printf("%d", i);
                }
                printf("\n");
            }
            if( amp >= 1 ){
                printf("\n");
            }
        }

    }


    return 0;
}
