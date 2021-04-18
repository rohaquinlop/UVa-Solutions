/*
*
* Problema UVA 574 - Sum It Up
*
*/
#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b){
	return a > b;
}

string convertInt(int n, int c){
	string s = bitset<32>(n).to_string();
	return s;
}

set< vector<int> > combinations( vector<int>& vec, int& c, int& val){
		set< vector<int> > combs;
		int i, numC = pow(2,c), j, sum;
		for(i = 1; i <= numC; i++){
			vector<int> temp;
			string s = convertInt(i, c);
			sum = 0;
			for(j = 32; j >= 0; j--){
				if( s[32-j] == '1' && 31-(32-j) < vec.size()){
					temp.push_back( vec[31-(32-j)] );
					sum += vec[31-(32-j)];
				}
			}

			if( sum == val ){
				sort(temp.begin(), temp.end(), cmp);
				combs.insert(temp);
			}
		}

		return combs;
}

int main(){
	int n, c;
	int i, aux;

	while( scanf("%d %d", &n, &c) == 2 ){
		if( n == 0 && c == 0 ){
			break;
		}else{
			vector<int> nums;
			for(i = 0; i < c; i++){
				scanf("%d", &aux);
				nums.push_back(aux);
			}

			printf("Sums of %d:\n", n);

			set< vector<int> > values = combinations(nums, c, n);
			if( values.size() > 0 ){
				set< vector<int> >::iterator it;
				stack< vector<int> > conj;

				for(it = values.begin(); it != values.end(); it++){
					vector<int> show = *it;
					conj.push(show);
				}

				while( !conj.empty() ){
					vector<int> show = conj.top();
					conj.pop();
					for(i = 0; i < show.size(); i++){
						printf("%d", show[i]);
						if( i < show.size()-1 ){
							printf("+");
						}
					}
					printf("\n");
				}
			}else{
				printf("NONE\n");
			}

		}
	}


	return 0;
}