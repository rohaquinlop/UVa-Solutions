/*
*
* Problema UVA 10341 - Solve It
*
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(){
	double p, q, r, s, t, u;
	double val0, val1;

	double xi, xu, xr;
	double valXi, valXr;

	while( scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) == 6 ){
		val0 = p*exp(0) + q*sin(0) + r*cos(0) + s*tan(0) + t*0*0 + u;
		val1 = p*exp(-1) + q*sin(1) + r*cos(1) + s*tan(1) + t*1*1 + u;
		if( ( val0 * val1 ) > 0 ){
			printf("No solution\n");
		}else{
			/* Teorema de Bolzano o Teorema de Biseccion */
			xi = 0;
			xu = 1;
			while( xi + 0.0000000001 < xu ){
				xr = (xi+xu)/2;
				valXi = p*exp(-xi) + q*sin(xi) + r*cos(xi) + s*tan(xi) + t*xi*xi + u;
				valXr = p*exp(-xr) + q*sin(xr) + r*cos(xr) + s*tan(xr) + t*xr*xr + u;
				if( ( valXi * valXr ) <= 0 ){
					xu = xr;
				}else if( ( valXi * valXr ) > 0 ){
					xi = xr;
				}
				
			}
			printf("%.4lf\n",(xi+xu)/2);

		}
	}

  return 0;
}
