/*
*
* Problema UVA 10420 - List of Conquests
*
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main(){
  int n, i;
  map<string, vector<string> > m;
  map<string, vector<string> >::iterator it;
  string line, country, name;
  bool found;

  scanf("%d\n", &n);

  while(n--){
    found = false;
    country = "";
    name = "";
    getline(cin, line);

    for(i = 0; i < line.size(); i++){
      if( line[i] == ' ' && !found && country.size() > 0 ){
        found = true;
      }else{
        if( !found && line[i] != ' ' ){
          country += line[i];
        }else if( found && line[i] != ' ' ){
          name += line[i];
        }
      }
    }

    m[country].push_back(name);
  }

  for(it = m.begin(); it != m.end(); it++){
    cout << it->first << " " << (it->second).size() << "\n";
  }


  return 0;
}
