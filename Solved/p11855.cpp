/*
*
* Problema UVa 11855 - Buzzwords
*
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> count_unique_substrings(string const& s) {
    int n = s.size();

    const int p = 53;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'A' + 1) * p_pow[i]) % m;

    vector<int> vals;
    for (int l = 1; l <= n; l++) {
    	vector<int> hs;
    	map<long long, int> can;
    	int accum = 1;
        for (int i = 0; i <= n - l; i++) {
            long long cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            if( find(hs.begin(), hs.end(), cur_h) != hs.end() ){
            	int internalVal = can[cur_h];
            	can[cur_h] = internalVal+1;
            	if( internalVal+1 > accum )
            		accum = internalVal+1;
            }
            else
            	can[cur_h] = 1;
            hs.push_back(cur_h);
        }
        if( accum == 1 )
        	break;
        vals.push_back(accum);
    }

    return vals;
}

int main(){
	int c = 0, i;
	string line, subString;

	while( getline(cin, line) ){

		if( line != "" ){
			line.erase(remove(line.begin(), line.end(), ' '), line.end());
			c++;
			subString = "";

			vector<int> res = count_unique_substrings(line);

			for(int i : res){
				printf("%d\n", i);
			}
			printf("\n");
		}
	}

	return 0;
}