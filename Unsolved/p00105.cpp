/*
 *
 * Problema UVa 105 - The Skyline Problem
 *
*/

#include <bits/stdc+.h>

using namespace std;

class Build{
public:
    int l;
    int h;
    int r;

public:
    Build(int _l, int _h, int _r){
        l = _l;
        h = _h;
        r = _r;
    }
};

int main(){
    vector<Build> builds;
    int l, h, r;

    while( scanf("%d %d %d", &l, &h, &r) == 3  ){
        builds.push_back( Build(l, h, r)  );
    }

    return 0;
}
