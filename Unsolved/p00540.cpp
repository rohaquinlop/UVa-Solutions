/*
 *
 * Problema UVa 540 - Team Queue
 *
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int teams, i, j, can, aux;
    string line, move;

    while( scanf("%d", &teams) == 1  ){
        if( teams == 0  ){
            break;
        }else{
            //Implementacion
            queue<int> cola;
            vector< int, int > nums;
            for(i = 0; i < teams; i++){
                scanf("%d", &can);
                for(j = 0; j < can; j++){
                    scanf("%d", &aux);
                    nums[aux] = can;
                }
            }

            while( getline(cin, line)  ){
                if( line == "STOP"  ){
                    break;
                }else{
                    if( line == "DEQUEUE" ){
                        //Hacer este procedimiento...
                    }else{
                    }
                }
            }
        }
    }


    return 0;
}
