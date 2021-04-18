/*
 *
 * Problema UVa 484 - The Department of Redundancy Department
 *
*/
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
	int num;
	map<long int, long int> m;
	vector<long int> v;
	map<long int, long int>::iterator it;
	vector<long int>::iterator it1;

	while( scanf("%li", &num) == 1 ){
		it = m.find(num);
		if( it != m.end() )
			m[num] += 1;
		else{
			v.push_back(num);
			m[num] = 1;
		}
	}
	
	for(it1 = v.begin(); it1 != v.end(); it1++){
		printf("%ld %ld\n", *it1, m[*it1]);
	}

	return 0;
}