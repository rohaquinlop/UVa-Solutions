/*
*
* Problema UVA 10469 - To Carry or not to Carry
*
*/

#include <bits/stdc++.h>

using namespace std;

string convert(int n){
	string s = bitset<32>(n).to_string();
	return s;
}

string sumBits(string n, string m){
	string result = "00000000000000000000000000000000";

	for(int i = n.size()-1; i >= 0; i-- ){
		if( n[i] != m[i] ){
			result[i] = '1';
		}
	}
	return result;
}

int convertInt(string c){
	int temp, num = 0;
	for(int i = 0; i < 32; i++){
		temp = c[i]-'0';
		num += (temp * pow(2, 31-i));
	}
	return num;
}

int main(){
	int n, m, sum;
	string b1, b2, aux;
	while( scanf("%d %d", &n, &m) == 2 ){
		printf("%d\n", convertInt( sumBits(convert(n), convert(m)) ));
	}

	return 0;
}