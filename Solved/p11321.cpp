/*
*
* Problema UVA 11321 - Sort! Sort!! And Sort!!!
*
*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Number{
public:
	int num;
	int module;

	Number(int x, int m){
		num = x;
		module = x%m;
	}

	bool operator<(const Number& n)const{
		if( module != n.module ){
			return module < n.module;
		}else{
			if( num%2 == 0 && n.num%2 != 0 ){
				return false;
			}
			if( num%2 == 0 && n.num%2 == 0 ){
				return num < n.num;
			}
			if( num%2 != 0 && n.num%2 != 0 ){
				return num > n.num;
			}
			return true;
		}
	}

};

int main(){
	int n, m, i, aux;

	while( scanf("%d %d", &n, &m) == 2 ){
		if( !n && !m ){
			printf("%d %d\n", n, m);
			break;
		}
		vector<Number> numbers;
		vector<Number>::iterator it;

		for(i = 0; i < n; i++){
			scanf("%d", &aux);
			numbers.push_back( Number(aux, m) );
		}

		sort(numbers.begin(), numbers.end());

		printf("%d %d\n", n, m);

		for(it = numbers.begin(); it != numbers.end(); it++){
			printf("%d\n", it->num);
		}

	}


	return 0;
}