/*
*
* Problema UVA 10377 - Maze Traversal
*
*/

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(){
  int maze[60][60];
  int cases, rows, columns, i, j, c, x, y, number;
  string line, aux;
  char action, eyes;

  number = 0;

  scanf("%d\n", &cases);

  while(cases){
    scanf("\n%d %d\n", &rows, &columns);
    eyes = 'N';

    for(i = 0; i < rows; i++){
      getline(cin, line);

      for(j = 0; j < columns; j++){
        aux = line[j];
        if(aux == " "){
          maze[i][j] = 0;
        }else{
          maze[i][j] = 1;
        }
      }
    }

    scanf("%d %d\n", &y, &x);
    y--;
    x--;

    while(scanf("%c", &action) == 1){
      if(action == 'Q'){
        break;
      }else{
        /* Lógica del movimiento en la mazmorra */

        if(action == 'R'){

          if(eyes == 'N'){
            eyes = 'E';
          }else if(eyes == 'W'){
            eyes = 'N';
          }else if(eyes == 'S'){
            eyes = 'W';
          }else if(eyes == 'E'){
            eyes = 'S';
          }


        }else if(action == 'L'){

          if(eyes == 'N'){
            eyes = 'W';
          }else if(eyes == 'W'){
            eyes = 'S';
          }else if(eyes == 'S'){
            eyes = 'E';
          }else if(eyes == 'E'){
            eyes = 'N';
          }


        }else if(action == 'F'){
          /* Como avanza el robot en el mapa | Verificaciones */
          if( (y > 0) && eyes == 'N' ){
            /* Codigo */
            if(maze[y-1][x] == 0){
              y--;
            }

          }else if( (x > 0) && eyes == 'W' ){
            /* Codigo */
            if(maze[y][x-1] == 0){
              x--;
            }

          }else if( (y < rows) && eyes == 'S' ){
            /* Codigo */
            if(maze[y+1][x] == 0){
              y++;
            }

          }else if( (x < columns) && eyes == 'E' ){
            /* Codigo */
            if(maze[y][x+1] == 0){
              x++;
            }

          }
        }

      }
    }

    if(number > 0){
      cout << endl;
    }
    y++;
    x++;

    cout << y << " " << x << " "<< eyes << endl;

    number++;



    cases--;
  }


  return 0;
}
