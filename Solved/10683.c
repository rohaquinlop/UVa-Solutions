/*
*
* Problema UVA 10863 - The decadary watch
*
*/ 
#include <stdio.h>

int main(){
	int hora, minuto, segundo, centseg;
	while(scanf("%2d%2d%2d%2d", &hora, &minuto, &segundo, &centseg) != EOF){
		int numDivisor = 24 * 60 * 60 * 100;
		int convCentesimas = (hora * 360000) + (minuto * 6000) + (segundo * 100) + centseg;
		int convSistemaDecimal = convCentesimas * 10;

		hora = convSistemaDecimal / numDivisor;

		convSistemaDecimal %= numDivisor;
		numDivisor /= 100;

		minuto = convSistemaDecimal / numDivisor;

		convSistemaDecimal %= numDivisor;
		numDivisor /= 100;

		segundo = convSistemaDecimal / numDivisor;

		convSistemaDecimal %= numDivisor;

		centseg = (convSistemaDecimal*100) / numDivisor;

		printf("%d%02d%02d%02d\n", hora, minuto, segundo, centseg);
	}		
	return 0;
}
