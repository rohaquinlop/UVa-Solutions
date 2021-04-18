/*
 *
 * Problema UVa 10260 - Soundex
 *
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main(){
    int i, count;
    bool space;
    string line, aux;
    map<char, int> values;
    map<char, int>::iterator it;

    values['B'] = 1;
    values['F'] = 1;
    values['P'] = 1;
    values['V'] = 1;
    values['C'] = 2;
    values['G'] = 2;
    values['J'] = 2;
    values['K'] = 2;
    values['Q'] = 2;
    values['S'] = 2;
    values['X'] = 2;
    values['Z'] = 2;
    values['D'] = 3;
    values['T'] = 3;
    values['L'] = 4;
    values['M'] = 5;
    values['N'] = 5;
    values['R'] = 6;

    while( getline(cin, line) ){
        space = false;
        count = 0;
        aux = "";
        int lastVal;
        for( i = 0; i < line.size(); i++ ){
            it = values.find(line[i]);
            if( it != values.end() ){
                char num[10];
                sprintf(num, "%d", it->second );
                if( count == 0 ){
                    aux += num;
                    space = false;
                    lastVal = it->second;
                }else{
                    if( space ){
                        aux += num;
                        space = false;
                        lastVal = it->second;
                    }else{
                        if( lastVal != it->second ){
                            aux += num;
                            lastVal = it->second;
                        }
                    }
                }
                count++;
            }else{
                space = true;
            }
        }
        cout << aux << "\n";
    }


    return 0;
}
