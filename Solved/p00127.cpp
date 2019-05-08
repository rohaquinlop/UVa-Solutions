/*
*
* Problema UVA 127 - "Accordian" Patience
*
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	vector< vector<string> > cards;
	vector<string> pile;
	string line, aux1, aux2;
	int i, max;
	bool find;

	while(true){
		cin >> line;
		if(line == "#"){
			break;
		}else{
			find = false;
			max = 52;
			pile.push_back(line);
			cards.push_back(pile);
			pile.clear();
			for(i = 0; i < max-1; i++ ){
				cin >> line;
				pile.push_back(line);
				cards.push_back(pile);
				pile.clear();
			}

			i = 0;

			while( i < cards.size() ){
				find = false;
				if(i >=3){
					aux1 = cards[i].back();
					aux2 = cards[i-3].back();
					if( aux1[0] == aux2[0] || aux1[1] == aux2[1]){
						cards[i-3].push_back( cards[i].back() );
						cards[i].pop_back();
						if(cards[i].size() == 0){
							cards.erase(cards.begin()+i);
						}
						find = true;
						i = 0;
					}
				}
				if( i >= 1){
					aux1 = cards[i].back();
					aux2 = cards[i-1].back();
					if( aux1[0] == aux2[0] || aux1[1] == aux2[1]){
						cards[i-1].push_back( cards[i].back() );
						cards[i].pop_back();
						if(cards[i].size() == 0){
							cards.erase(cards.begin()+i);
						}
						find = true;
						i = 0;
					}
				}
				if(find == true){
					continue;
				}else if(find == false){
					i++;
				}
			}

			if( cards.size() == 1 ){
				cout << "1 pile remaining: 52" << endl;
			}else{
				cout << cards.size() << " piles remaining:";

				for(i = 0; i < cards.size(); i++){
					cout <<" " << cards[i].size();
				}
				cout << endl;
			}

			cards.clear();
			pile.clear();
		}
	}


	return 0;
}