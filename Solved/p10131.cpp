/*
*
* Problema UVA 10131 - Is Bigger Smarter?
*
*/
#include <bits/stdc++.h>

using namespace std;

class Elephant{
public:
	int w;
	int iq;
	int i;

public:
	Elephant(int s, int iq, int i){
		this->w = s;
		this->iq = iq;
		this->i = i;
	}

	bool operator<(Elephant& e){
		if( e.w == this->w ){
			return this->iq > e.iq;
		}
		return this->w < e.w;
	}
};

void printLIS(vector<Elephant>& arr){
	printf("%d\n", arr.size());
    for (Elephant x : arr)
        printf("%d\n", x.i);
}

void constructPrintLIS(vector<Elephant> arr, int n){
    vector< vector<Elephant> > L(n);
    L[0].push_back(arr[0]);

    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if ( ( arr[i].w > arr[j].w && arr[i].iq < arr[j].iq )
            	&& (L[i].size() < L[j].size() + 1))
                L[i] = L[j];
        }

        L[i].push_back(arr[i]);
    }

    vector<Elephant> max = L[0];

    for (vector<Elephant> x : L)
        if (x.size() > max.size())
            max = x;

	printLIS(max);
}

int main(){
	int s, iq, i = 1;
	vector<Elephant> elephants;

	while( scanf("%d %d", &s, &iq) == 2 ){
		elephants.push_back( Elephant(s, iq, i) );
		i++;
	}

	sort(elephants.begin(), elephants.end());

	constructPrintLIS(elephants, elephants.size());



	return 0;
}