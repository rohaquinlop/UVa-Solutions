/*
*
* Problema UVA 10698 - Football Sort
*
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Team{
public:
	char name[20];
	int points;
	int gPlayed;
	int gScored;
	int gAgainst;
	int gDiff;
	double percent;

	Team(char* n){
		strcpy(name, n);
		points = 0;
		gPlayed = 0;
		gScored = 0;
		gAgainst = 0;
		gDiff = 0;
		percent = 0.000;
	}

	bool operator<(const Team& t){
		if( points != t.points ){
			return points > t.points;
		}else if( gDiff != t.gDiff ){
			return gDiff > t.gDiff;
		}else if( gScored != t.gScored ){
			return gScored > t.gScored;
		}else{
			string n1 = name;
			string n2 = t.name;

			std::transform(n1.begin(), n1.end(), n1.begin(), ::tolower);
			std::transform(n2.begin(), n2.end(), n2.begin(), ::tolower);

			return n1 < n2;
		}
	}

};

int main(){
	int t, g, i;
	char team[20], line[100];

	char teamA[20], teamB[20];
	int gA, gB, posTeam, c = 0;

	while(1){
		scanf("%d %d\n", &t, &g);
		if( t == 0 && g == 0 ){
			break;
		}else{
			c++;
			vector<Team> teams;
			vector<Team>::iterator it;

			for(i = 0; i < t; i++){
				scanf("%s\n", team);
				teams.push_back( Team(team) );
			}

			for(i = 0; i < g; i++){
				scanf("%s %d - %d %s\n", teamA, &gA, &gB, teamB);

				if( gA == gB ){
					for( vector<Team>::iterator it = teams.begin(); it != teams.end(); it++ ){
						if( !strcmp(it->name, teamA) ){
							it->points++;
							it->gPlayed++;
							it->gScored += gA;
							it->gAgainst += gB;
							it->gDiff = ((it->gScored) - (it->gAgainst));
						}
						if( !strcmp(it->name, teamB) ){
							it->points++;
							it->gPlayed++;
							it->gScored += gB;
							it->gAgainst += gA;
							it->gDiff = ((it->gScored) - (it->gAgainst));
						}
					}
				}else if( gA > gB ){
					for( vector<Team>::iterator it = teams.begin(); it != teams.end(); it++ ){
						if( !strcmp(it->name, teamA) ){
							it->points += 3;
							it->gPlayed++;
							it->gScored += gA;
							it->gAgainst += gB;
							it->gDiff = ((it->gScored) - (it->gAgainst));
						}
						if( !strcmp(it->name, teamB) ){
							it->gPlayed++;
							it->gScored += gB;
							it->gAgainst += gA;
							it->gDiff = ((it->gScored) - (it->gAgainst));
						}
					}
				}else{
					for( vector<Team>::iterator it = teams.begin(); it != teams.end(); it++ ){
						if( !strcmp(it->name, teamB) ){
							it->points += 3;
							it->gPlayed++;
							it->gScored += gB;
							it->gAgainst += gA;
							it->gDiff = ((it->gScored) - (it->gAgainst));
						}
						if( !strcmp(it->name, teamA) ){
							it->gPlayed++;
							it->gScored += gA;
							it->gAgainst += gB;
							it->gDiff = ((it->gScored) - (it->gAgainst));
						}
					}
				}
			}

			posTeam = 0;

			/* Calcular el porcentaje de puntos ganados */
			for( vector<Team>::iterator it = teams.begin(); it != teams.end(); it++ ){	
				it->percent = ( (it->points*100) / (double)(it->gPlayed*3) );
			}

			sort(teams.begin(), teams.end());

			if(c > 1){
				printf("\n");
			}

			for( vector<Team>::iterator it = teams.begin(); it != teams.end(); it++ ){
				posTeam++;
				if(teams.begin()-it == 0 || it->points != (it-1)->points || it->gScored != (it-1)->gScored ||
					it->gDiff != (it-1)->gDiff){
					printf("%2d. ", posTeam );
				}else{
					printf("%4s", "    ");
				}

				printf("%15s %3d %3d %3d %3d %3d ", it->name, it->points, it->gPlayed, it->gScored, it->gAgainst, it->gDiff);

				if( it->gPlayed == 0 ){
					printf("   N/A\n");
				}else{
					printf("%6.2lf\n", it->percent);
				}

			}

		}

	}

	return 0;
}