/*
*
* Problema UVA 10194 - Football (aka Soccer)
*
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

char to_lowercase(char c){
	if( c >= 'A' && c <= 'Z' ){
		return c+32;
	}
	else{
		return c;
	}
}

class Team{
	public:
		string name;
		int points;
		int gPlayed;
		int wins;
		int ties;
		int losses;
		int gDiff;
		int gScored;
		int gAgainst;

		Team( string n ){
			name = n;
			points = 0;
			gPlayed = 0;
			wins = 0;
			ties = 0;
			losses = 0;
			gDiff = 0;
			gScored = 0;
			gAgainst = 0;
		}
		
		bool operator <(const Team& team) const{
          if( points != team.points ){
          	return points > team.points;
          }if( wins != team.wins ){
          	return wins > team.wins;
          }else if( gDiff != team.gDiff ){
          	return gDiff > team.gDiff;
          }else if( gScored != team.gScored ){
          	return gScored > team.gScored;
          }else if( gPlayed != team.gPlayed ){
          	return gPlayed < team.gPlayed;
          }else{
          	string cmp1, cmp2;
          	cmp1 = name, cmp2 = team.name;

          	for(int i = 0; i < cmp1.size(); i++){
          		cmp1[i] = to_lowercase(cmp1[i]);
          	}

          	for(int i = 0; i < cmp2.size(); i++){
          		cmp2[i] = to_lowercase(cmp2[i]);
          	}

          	return cmp1 < cmp2;
          }
      	}
};

int main(){
	int n, t, g, c = 0;
	int i, j, sA, sB;
	string tName, line, tournament;
	string teamA, teamB, scoreA, scoreB;

	scanf("%d\n", &n);

	while(n--){
		c++;
		vector <Team> teams;

		getline(cin, tournament);
		scanf("%d\n", &t);

		for(i = 0; i < t; i++){
			getline(cin, tName);
			teams.push_back( Team(tName) );
		}

		scanf("%d\n", &g);

		for(i = 0; i < g; i++){
			getline(cin, line);
			teamA = "";
			teamB = "";
			scoreA = "";
			scoreB = "";
			for(j = 0; j < line.size(); j++){
				if( line[j] == '#' ){
					j++;
					break;
				}
				else{
					teamA += line[j];
				}
			}

			for(j; j < line.size(); j++){
				if( line[j] == '@' ){
					j++;
					break;
				}
				else{
					scoreA += line[j];
				}
			}

			for(j; j < line.size(); j++){
				if( line[j] == '#' ){
					j++;
					break;
				}
				else{
					scoreB += line[j];
				}
			}

			for(j; j < line.size(); j++){
				teamB += line[j];
			}

			const char* cv1 = scoreA.c_str();
			const char* cv2 = scoreB.c_str();

			sA = atoi(cv1);
			sB = atoi(cv2);

			if( sA == sB ){
				for( vector<Team>::iterator it = teams.begin(); it != teams.end(); it++ ){
					if( it->name == teamA ){
						it->points++;
						it->gPlayed++;
						it->ties++;
						it->gScored += sA;
						it->gAgainst += sB;
						it->gDiff = ((it->gScored) - (it->gAgainst));
					}
					if( it->name == teamB ){
						it->points++;
						it->gPlayed++;
						it->ties++;
						it->gScored += sB;
						it->gAgainst += sA;
						it->gDiff = ((it->gScored) - (it->gAgainst));
					}
				}
			}else if( sA > sB ){
				for( vector<Team>::iterator it = teams.begin(); it != teams.end(); it++ ){
					if( it->name == teamA ){
						it->points += 3;
						it->gPlayed++;
						it->wins++;
						it->gScored += sA;
						it->gAgainst += sB;
						it->gDiff = ((it->gScored) - (it->gAgainst));
					}
					if( it->name == teamB ){
						it->gPlayed++;
						it->losses++;
						it->gScored += sB;
						it->gAgainst += sA;
						it->gDiff = ((it->gScored) - (it->gAgainst));
					}
				}
			}else{
				for( vector<Team>::iterator it = teams.begin(); it != teams.end(); it++ ){
					if( it->name == teamB ){
						it->points += 3;
						it->gPlayed++;
						it->wins++;
						it->gScored += sB;
						it->gAgainst += sA;
						it->gDiff = ((it->gScored) - (it->gAgainst));
					}
					if( it->name == teamA ){
						it->gPlayed++;
						it->losses++;
						it->gScored += sA;
						it->gAgainst += sB;
						it->gDiff = ((it->gScored) - (it->gAgainst));
					}
				}
			}
		}

		sort( teams.begin(), teams.end() );

		if( c > 1){
			printf("\n");
		}
		cout << tournament << "\n";
		int count = 1;
		for( vector<Team>::iterator it = teams.begin(); it != teams.end(); it++ ){
			cout << count << ") " << it->name << " " << it->points << "p, " << it->gPlayed << "g (";
			cout << it->wins << "-" << it->ties << "-" << it->losses << "), ";
			cout << it->gDiff << "gd (" << it->gScored << "-" << it->gAgainst << ")" << "\n";
			count++;
		}

	}

	return 0;
}