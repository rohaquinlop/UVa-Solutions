/*
*
* Problema UVA 11507 - Bender B. Rodríguez Problem
*
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	long int cases, i;
	vector<string> moves;
	string move, look;

	while(1){
		scanf("%lli\n", &cases);
		if(cases == 0){
			break;
		}else{
			for(i = 1; i < cases; i++){
				cin>>move;
				moves.push_back(move);
			}

			look = "+x";

			for(i = 0; i < moves.size(); i++){
				move = moves.at(i);

				if(move == "+z"){
					if(look == "+x"){
						look = "+z";
					}
					else if(look == "+z"){
						look = "-x";
					}
					else if(look == "-x"){
						look = "-z";
					}
					else if(look == "-z"){
						look = "+x";
					}
				}

				else if(move == "-z"){
					if(look == "+x"){
						look = "-z";
					}
					else if(look == "-z"){
						look = "-x";
					}
					else if(look == "-x"){
						look = "+z";
					}
					else if(look == "+z"){
						look = "+x";
					}
				}

				else if(move == "+y"){
					if( look == "+x" ){
						look = "+y";
					}
					else if( look == "+y" ){
						look = "-x";
					}
					else if( look == "-x" ){
						look = "-y";
					}
					else if( look == "-y" ){
						look = "+x";
					}
				}

				else if(move == "-y"){
					if( look == "+x" ){
						look = "-y";
					}
					else if( look == "-y" ){
						look = "-x";
					}
					else if( look == "-x" ){
						look = "+y";
					}
					else if( look == "+y" ){
						look = "+x";
					}
				}

				else if(move == "No"){
					continue;
				}

			}

			cout << look << endl;


			moves.clear();
		}
	}

	return 0;
}
