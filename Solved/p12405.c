/*
*
* Problema UVA 12405 - Scarecrow
*
* Explicación: Lo que pide el problema es decir la cantidad de espantapájaros que se necesitan en un campo de manera
* que se logre cubrir todos los cultivos que hay (el espatapájaros cubre 1 unidad al lado derecho y 1 unidad al lado
* izquierdo), en ese mismo terreno tambien hay tierra en la cual no hay cultivos.
* Para solucionar este problema lo que se hace es tomar el string que me indica cual es la forma que tiene el campo
* si es un cultivo (.), si no hay un cultivo (#) y se convierte en un arreglo de enteros (1 si es un cultivo, 0 si no
* hay cultivos); se recorre el arreglo de enteros verificando si en esa posición hay un cultivo, si es así entonces
* esa posicion mas uno a la derecha se cambia por el valor dos y el iterador aumenta en 2 posiciones para que así se
* optimice la cobertura con los espantapájaros. Para evitar errores en casos especiales lo que se hizo fue que se
* verificara si el iterador estaba ya en la ultima posicion y en caso de que así fuera entonces se marcara esa zona
* con un dos (solo sucede en caso de que no haya sido marcada). Al finalizar el recorrido, se cuenta la cantidad de
* espantapájaros (que es el numero 2) y esa sería la respuesta.
*
* Complejidad: T(n) O(n), es linear ya que se recorre todo el arreglo.
*
*/

#include <stdio.h>

int main(){
	int cases;
	int n, i;
	char input;
	int c = 0, sec;
	int field[101];
	int array[101];

	scanf("%d\n", &cases);

	while(cases--){
		c++;
		scanf("%d\n", &n);

		for(i = 0; i < n; i++){
			scanf("%c", &input);
			if(input == '.'){
				field[i] = 1;
			}else{
				field[i] = 0;
			}
		}
		scanf("%c", &input);

		sec = 0;

		for(i = 0; i < n; i++){
			if( field[i] == 1 ){
				if( i < n-1 ){
					field[i+1] = 2;
					i += 2;
					sec++;
				}else{
					field[i] = 2;
					sec++;
				}
			}
		}

		printf("Case %d: %d\n", c, sec);

	}


	return 0;
}
