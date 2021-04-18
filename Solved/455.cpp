/*
*
* Problema UVa 455 - Periodic Strings
*
*/

#include <bits/stdc++.h>

using namespace std;

int rabin_karp(string const& s, string const& t) {
    const int p = 53;
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'A' + 1) * p_pow[i]) % m; 

    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'A' + 1) * p_pow[i]) % m; 

    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) { 
        long long cur_h = (h[i+S] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }

    vector<int> res;
    if( occurences.size() >= 1 )
    	res.push_back(occurences[0]);

    for(int i = 1; i < occurences.size(); i++)
    	if( occurences[i] - occurences[i-1] >= s.size() )
    		res.push_back(occurences[i]);

    return res.size();
}

int main(){
	int cases, minPeriod, c = 0;
	string line, subString;

	scanf("%d\n\n", &cases);

	while(cases--){
		getline(cin, line);
		subString = "";
		minPeriod = line.size();
		c++;

		for(int i = 1; i <= line.size(); i++){
			subString += line[i-1];
			int res = rabin_karp(subString, line)*i;
			if( res == line.size() )
				if( i < minPeriod )
					minPeriod = i;
		}

		if( c > 1 )
			printf("\n");
		printf("%d\n", minPeriod);

		getline(cin, line);
	}


	return 0;
}