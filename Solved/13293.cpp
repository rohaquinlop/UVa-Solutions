/*
*
* Problema UVa 13293 - All-star Three-point Contest
*
*/

#include <bits/stdc++.h>

using namespace std;

class Player{
public:
	string name;
	int points;

public:
	Player(string n, int p){
		this->name = n;
		this->points = p;
	}

	bool operator<(const Player& p){
		if( p.points == this->points ){
			string n1 = this->name;
			string n2 = p.name;
			transform(n1.begin(), n1.end(), n1.begin(), ::tolower);
			transform(n2.begin(), n2.end(), n2.begin(), ::tolower);
			return n1 < n2;
		}
		return this->points > p.points;
	}

};

int main(){
	int n, i, j, c = 0;
	string line;

	while( scanf("%d\n", &n) == 1 ){
		c++;
		vector<Player> players;
		vector<Player>::iterator it;

		for(int i = 0; i < n; i++){
			getline(cin, line);
			string name = "";
			for(j = 0; j < line.size(); j++){
				if( line[j] != ';' ) name += line[j];
				else{
					j++;
					break;
				}
			}
			int points = 0;
			int count = 0;
			for(j; j < line.size(); j++){
				if( line[j] != ' ' && line[j] != ';' ){
					count++;
					if( count == 5 ){
						points += 2*(line[j]-'0');
						count = 0;
					}
					else{
						points += line[j]-'0';
					}

				}
			}
			players.push_back( Player(name, points) );
		}

		sort(players.begin(), players.end());
		printf("Case %d:\n", c);
		for(it = players.begin(); it != players.end(); it++){
			cout << it->name << " " << it->points << "\n";
		}

	}


	return 0;
}