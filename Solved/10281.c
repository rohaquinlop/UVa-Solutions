/*
*
* Problema UVA 10281 - Average Speed
*
*/

#include <stdio.h>
#include <string.h>

int main(){
	char line[100000];
	int hh, mm, ss;
	double lTime = 0, aTime, vel = 0, lDistance = 0, aDistance;

	while( gets(line) ){

		sscanf(line, "%2d:%2d:%2d", &hh, &mm, &ss);
		aTime = hh + (mm/60.0) + (ss/3600.0);

		if( line[8] == '\0' ){
			lDistance += (aTime - lTime) * vel;
			printf("%s %.2lf km\n", line, lDistance);
		}else{
			lDistance += (aTime - lTime)*vel;
			sscanf(line, "%2d:%2d:%2d %lf", &hh, &mm, &ss, &vel);
		}

		lTime = aTime;
	}
	
	return 0;
}