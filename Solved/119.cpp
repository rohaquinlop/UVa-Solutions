/*
*
* Problema UVA 119 - Greedy Gift Givers
*
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <cstddef>

using namespace std;

int main(){
  int cPersonas, i, grupo;
  string nombre;
  vector<string> vNombres(10); /* Vector que contiene los nombres del grupo de personas */
  int vRegalos[10]; /* arreglo que indica el total de los regalos, es decir, cuanto obtuvo cada uno */
  string rNombre; /* Nombre de la persona que regala */
  ptrdiff_t pos; /* Posicion del nombre en el arreglo | tipo entero con signo del resultado de restar dos punteros */

  int dinero;
  int cRegalos;
  int dRegalo;
  int salto;

  salto = 0;

  while( scanf("%d", &cPersonas) == 1 ){

    grupo = cPersonas;

    for(i = 0; i < cPersonas; i++){
      cin >> nombre;
      vNombres[i] = nombre;
      vRegalos[i] = 0;
    }

    while(cPersonas){
      cin >> nombre;

      pos = find(vNombres.begin(), vNombres.end(), nombre) - vNombres.begin();

      cin >> dinero;
      cin >> cRegalos;

      if( cRegalos > 0 ){
        dRegalo = (dinero/cRegalos);
        vRegalos[pos] -= (dRegalo*cRegalos);


        while(cRegalos > 0){
          cin >> nombre;
          pos = find(vNombres.begin(), vNombres.end(), nombre) - vNombres.begin();
          vRegalos[pos] += dRegalo;
          cRegalos--;
        }
      }

      cPersonas--;
    }

    if(salto != 0){
      cout<<endl;
    }

    for(i = 0; i < grupo; i++){
      cout << vNombres[i]<< " " << vRegalos[i] << endl;
    }
    salto++;
  }
}
