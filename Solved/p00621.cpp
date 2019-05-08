/*
*
* Problema UVA 621 - Secret Research
*
*/

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

int main(){
	string s, aux1, aux2, aux3, aux4, aux5, aux6;
	int cases, len;
	stringstream ss;

	scanf("%d", &cases);

	while(cases--){
		cin >> s;
		len = s.length();
		ss.str("");
		
		ss << s[len-2] << s[len-1];
		aux1 = ss.str(); /* 35 */

		ss.str("");
		ss << s[0];
		aux2 = ss.str(); /* 9 */

		ss.str("");
		ss << s[len-1];
		aux3 = ss.str(); /* 4 */

		ss.str("");
		ss << s[0] << s[1] << s[2];
		aux4 = ss.str(); /* 190 */

		ss.str("");
		ss << s[0];
		aux5 = ss.str(); /* 1 */

		ss.str("");
		ss << s[len-2] << s[len-1];
		aux6 = ss.str(); /* 78 */

		if( aux1 == "35" ){
			cout << "-" << endl;
		}else if( aux2 == "9" && aux3 == "4" ){
			cout << "*" << endl;
		}else if( (aux5 == "1" && len == 1) || (aux3 == "4" && len == 1) || (aux6 == "78" && len == 2)){
			cout << "+" << endl;
		}else if( aux4 == "190" ){
			cout << "?" << endl;
		}else{
			cout << "?" << endl;
		}
	}
	
	return 0;
}