/*
*
* Problema UVA 139 - Telephone Tangles
*
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
	int i, j, cvertion, duration, pos, tam;
	float cost;
	string line, code, name, price, aux, comp;
	string number, susNumber;

	vector< vector<string> > codes;
	vector<int> prices;
	while( getline(cin, line) ){
		if(line == "000000"){

			while( cin >> number){
				if( number == "#" ){
					break;
				}else{
					cin >> duration;
					pos = -1;
					aux = number[0];

					if( aux != "0" ){
						printf("%-16s%-25s%10s%5d%6.2f%7.2f\n", number.c_str(), "Local",
	                           number.c_str(), duration, 0.0000, 0.0000);
					}else{
						for(i = 0; i < codes.size(); i++){
							aux = codes[i][1];
							if( aux.size() <= number.size() ){
								comp = number.substr(0, aux.size());
								if( number[0] == '0' && number[1] == '0' && ((number.size()-aux.size()) <= 10) && ((number.size()-aux.size()) >= 4) ){
									if( aux == comp && pos == -1){
										tam = aux.size();
										pos = i;
									}
								}else if( number[0] == '0' && number[1] != '0' && (number.size()-aux.size() <= 7) && (number.size()-aux.size() >= 4) ){
									if( aux == comp && pos == -1){
										tam = aux.size();
										pos = i;
									}
								}
							}
						}

						if( pos != -1 ){
							cost = duration*prices[pos]/(float)100;
							susNumber = number.substr(tam,number.size()-1);
							printf("%-16s%-25s%10s%5d%6.2f%7.2f\n", number.c_str(), codes[pos][0].c_str(),
	                           susNumber.c_str(), duration, (float)prices[pos]/100, cost);
						}else{
							printf("%-15s %-35s%5d%13.2lf\n", number.c_str(), "Unknown", duration, -1.0);
						}
					}

				}
			}

			if(number == "#"){
				break;
			}

		}else{
			code = "";
			name = "";
			price = "";

			for(i = 0; i < line.size(); i++){
				aux = line[i];
				if( aux == " "){
					break;
				}else{
					code += line[i];
				}
			}
			i++;
			for(i; i < line.size(); i++){
				aux = line[i];
				if(aux == "$"){
					break;
				}else{
					name += line[i];
				}
			}
			i++;
			for(i; i < line.size(); i++){
				aux = line[i];
				price += aux;
			}

			cvertion = stoi(price);

			vector<string> v;
			v.push_back(name);
			v.push_back(code);
			codes.push_back(v);
			prices.push_back(cvertion);
		}
	}



	return 0;
}
