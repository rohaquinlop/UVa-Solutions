/*
*
* Problema UVA 924 - Spreading the News
*
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, i, j, aux, nStart, tam, num, cases;

	while( scanf("%d", &n) == 1 ){
		map<int, vector<int> > graph;
		for(i = 0; i < n; i++){
			scanf("%d", &num);
			for(j = 0; j < num; j++){
				scanf("%d", &aux);
				graph[i].push_back(aux);
			}
		}

		scanf("%d", &cases);

		while(cases--){
			scanf("%d", &nStart);

			//BFS
			int maxHears = 0, day = 0;
			int visited[n] = {0};
			int days[n] = {0};
			int friends[n+1] = {0};
			queue<int> cola; cola.push(nStart);
			visited[nStart] = 1;

			while(!cola.empty()){
				nStart = cola.front(); cola.pop();
				tam = graph[nStart].size();
				days[nStart]++;

				for(i = 0; i < tam; i++){
					aux = graph[nStart][i];
					if( !visited[aux] ){
						visited[aux] = 1;
						days[aux] = days[nStart];
						friends[days[nStart]]++;
						if( friends[days[nStart]] > maxHears ){
							maxHears = friends[days[nStart]];
							day = days[nStart];
						}
						cola.push(aux);
					}
				}
			}

			if( maxHears )
				printf("%d %d\n", maxHears, day);
			else
				printf("0\n");
		}

	}
}