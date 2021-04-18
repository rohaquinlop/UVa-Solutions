/*
*
* Problema UVa 790 - Head Judge Headache
*
*/
#include <bits/stdc++.h>

using namespace std;

class Input{
public:
	int teamNum;
	char letter;
	int h;
	int mins;
	char status;

public:
	Input(int tNum, char l, int h, int mins, char status){
		this->teamNum = tNum;
		this->letter = l;
		this->h = h;
		this->mins = mins;
		this->status = status;
	}

	bool operator<(Input& i){
		if( this->letter == i.letter ){
			if( ((this->h*60)+this->mins) == ((i.h*60)+i.mins) ){
				return this->status < i.status;
			}
			return ((this->h*60)+this->mins) < ((i.h*60)+i.mins);
		}
		return this->letter < i.letter;
	}
};

class Team{
public:
	int tNum;
	int solved[7] = {0};
	int tried[7] = {0};
	int tSolved = 0;
	int tTime = 0;

public:

	Team(){
		tNum = -1;
	}

	Team(int num){
		this->tNum = num;
	}

	bool operator<(Team& t){
		if( this->tSolved == t.tSolved ){
			if( this->tTime == t.tTime ){
				return this->tNum < t.tNum;
			}
			return this->tTime < t.tTime;
		}
		return this->tSolved > t.tSolved;
	}
};

int main(){
	int teamNum, h, mins, cases, maxTeam, c = 0, tCases;
	char pLetter, status;
	string line;

	scanf("%d\n\n", &cases);
	tCases = cases;

	while(cases--){
		maxTeam = 1;
		vector<Team> teams(40);
		int isAdded[40] = {0};
		vector<Input> inputs;
		while( true ){
			getline(cin, line);
			if( line == "" ){
				sort(inputs.begin(), inputs.end());

				for(int i = 0; i < inputs.size(); i++){
					teamNum = inputs[i].teamNum;
					pLetter = inputs[i].letter;
					h = inputs[i].h;
					mins = inputs[i].mins;
					status = inputs[i].status;

					if( !isAdded[teamNum-1] ){
						teams[teamNum-1] = Team(teamNum);
						isAdded[teamNum-1]++;
					}

					if( teams[teamNum-1].solved[pLetter-'A'] == 0 ){
						if( status == 'N' )
							teams[teamNum-1].tried[pLetter-'A']++;
						else{
							teams[teamNum-1].tSolved++;
							teams[teamNum-1].solved[pLetter-'A'] = 1;
							teams[teamNum-1].tTime += (h*60)+mins + ((teams[teamNum-1].tried[pLetter-'A'])*20);
						}
					}
				}


				c++;
				for(int i = 0; i < maxTeam; i++){
					if( !isAdded[i] ){
						teams[i] = Team(i+1);
					}
				}

				sort(teams.begin(), teams.begin()+maxTeam);
				vector<Team>::iterator it;

				printf("RANK TEAM PRO/SOLVED TIME\n");
				int rank = 1;
				int ansRank = 1;
				for(it = teams.begin(); it != teams.begin()+maxTeam; it++){
					if( it->tSolved > 0 ){
						if( it > teams.begin() ){
							if( it->tSolved == (it-1)->tSolved && it->tTime == (it-1)->tTime ){
								printf("%4d %4d %4d       %4d\n", ansRank, it->tNum, it->tSolved, it->tTime);
							}
							else{
								printf("%4d %4d %4d       %4d\n", rank, it->tNum, it->tSolved, it->tTime);
								ansRank = rank;
							}
							rank++;
						}
						else{
							printf("%4d %4d %4d       %4d\n", rank, it->tNum, it->tSolved, it->tTime);
							ansRank = rank;
							rank++;
						}
					}
					else{
						printf("%4d %4d\n", rank, it->tNum);
					}
				}

				if( cases > 0 )
					printf("\n");
				break;
			}
			else{
				sscanf(line.c_str(), "%d %c %d:%2d %c", &teamNum, &pLetter, &h, &mins, &status);
				if( teamNum > maxTeam) maxTeam = teamNum;

				inputs.push_back( Input(teamNum, pLetter, h, mins, status) );
			}
		}
	}


	return 0;
}