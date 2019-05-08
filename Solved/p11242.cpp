/*
*
* Problema UVA 11242 - Tour de France
*
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int compare(const void * a, const void * b) {
	double fa = *(const double*) a;
	double fb = *(const double*) b;
	return (fa > fb) - (fa < fb);
}

int main(){
	int cFrontal, cTrasero, i, j, n, m, pos, tam;
	double mSpread, tSpread, aux;

	while( scanf("%d", &cFrontal) == 1 ){
		if( cFrontal == 0 ){
			break;
		}else{
			scanf("%d", &cTrasero);

			int front[cFrontal];
			int rear[cTrasero];
			tam = cFrontal*cTrasero;
			double drives[tam];

			for(i = 0; i < cFrontal; i++){
				scanf("%d", &front[i]);
			}

			for(i = 0; i < cTrasero; i++){
				scanf("%d", &rear[i]);
			}

			pos = 0;
			for(i = 0; i < cTrasero; i++){
				for(j = 0; j < cFrontal; j++){
					n = rear[i];
					m = front[j];
					aux = (double)n/(double)m;
					drives[pos] = aux;
					pos++;
				}
			}

			qsort(drives, tam, sizeof(double), compare);

			mSpread = (double)0;

			for(i = 1; i < tam; i++){
				tSpread = drives[i]/drives[i-1];
				if(tSpread > mSpread){
					mSpread = tSpread;
				}
			}

			printf("%.2lf\n", mSpread);

		}
	}


	return 0;
}
