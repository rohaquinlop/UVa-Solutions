/*
*
* Problema UVA 612 - DNA Sorting
*
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Dataset{
public:
	char dna[50];
	int inversion;
	int entry;

	Dataset( char* d, int n, int e){
		strcpy(dna, d);
		inversion = n;
		entry = e;
	}

	bool operator <(const Dataset& data){
		if( inversion != data.inversion ){
			return inversion < data.inversion;
		}
		return entry < data.entry;
	}
};

int main(){
	int cases, n, m, i, j, k, inversion, diff1, diff2, c = 0;;
	char dnaUnsort[50];

	scanf("%d", &cases);

	while( cases-- ){
		c++;
		vector<Dataset> datasets;
		vector<Dataset>::iterator it;

		scanf("%d %d\n", &n, &m);

		for(i = 0; i < m; i++){
			scanf("%s", dnaUnsort);

			inversion = 0;

			for(j = 0; j < n; j++){
				for(k = j+1; k < n; k++){
					if( dnaUnsort[j] > dnaUnsort[k] ){
						inversion++;
					}
				}
			}

			datasets.push_back( Dataset(dnaUnsort, inversion, i) );
		}

		sort(datasets.begin(), datasets.end());

		if(c > 1){
			printf("\n");
		}

		for(it = datasets.begin(); it != datasets.end(); it++){
			printf("%s\n", it->dna);
		}
	}

	return 0;
}