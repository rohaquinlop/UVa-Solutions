/*
*
* Problema UVA 272 - TEX Quotes
*
*/

#include <stdio.h>

int main(){
    char line;
    int band = 0;

    while( scanf("%c", &line) == 1 ){
        if( line == '"' ){
            band++;
            if( band%2 ){
                printf("``");
            }else{
                printf("''");
            }
        }else{
            printf("%c", line);
        }
    }


    return 0;
}