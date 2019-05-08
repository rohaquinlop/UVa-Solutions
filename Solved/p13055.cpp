/*
 *
 * Problema UVa 13055 - Inception
 *
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int cases, i;
    string line, name;
    stack<string> pila;

    scanf("%d\n", &cases);

    while(cases--){
        getline(cin, line);
        
        if( line.size() == 4 ){
            if( line == "Test"  ){
                if( !pila.empty()  ){
                    name = pila.top();
                    cout << name << "\n";
                }else{
                    cout << "Not in a dream" << "\n";
                }
            }else{
                if( !pila.empty()  ){
                    pila.pop();
                }
            }
        }else{
            name = "";
            for(i = 6; i < line.size(); i++)
                name += line[i];
            pila.push(name);
        }
    }

    return 0;
}
