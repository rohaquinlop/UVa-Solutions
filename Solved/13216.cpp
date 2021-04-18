/*
*
* Problema UVA 13216 - Problem with a ridiculously long name but with a ridiculously short description
*
*/

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
	int cases;
	int len;
	string n, m;

	scanf("%d", &cases);

	while(cases--){
		cin >> n;
		if(n == "0"){
			printf("1\n");
		}else if(n == "1"){
			printf("66\n");
		}else{
			len = n.length();
			m = n.at(len-1);
			if( m == "1" || m == "6" ){
				printf("16\n");
			}else if( m == "2" || m == "7" ){
				printf("56\n");
			}else if( m == "3" || m == "8" ){
				printf("96\n");
			}else if( m == "4" || m == "9" ){
				printf("36\n");
			}else if( m == "5" || m == "0" ){
				printf("76\n");
			}
		}
	}


	return 0;
}