/*
*
* Problema UVA 10550 - Combination Lock
*
*/

#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int d, p1, p2, p3;
	int angle, count;

	while( scanf("%d %d %d %d", &d, &p1, &p2, &p3) == 4 ){
		if( d == 0 && p1 == 0 && p2 == 0 && p3 == 0){
			break;
		}else{
			angle = 1080;
			count = 0;

			if( (d-p1) < 0 ){
				count += d-p1+40;
			}else{
				count += d-p1;
			}
			if( (p2-p1) < 0 ){
				count += p2-p1+40;
			}else{
				count += p2-p1;
			}
			if( (p2-p3) < 0 ){
				count += p2-p3+40;
			}else{
				count += p2-p3;
			}
			count *= 9;
			angle += count;

			cout << angle << endl;
		}


	}

	return 0;
}