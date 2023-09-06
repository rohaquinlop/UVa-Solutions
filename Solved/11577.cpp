#include <stdio.h>

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
  int t, most_freq;
  string s;

  scanf("%d\n", &t);

  while (t--) {
    getline(cin, s);
    most_freq = 0;

    vector<int> m(26, 0);

    for (char &c : s) {
      if ((c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z')) {
        if (c >= 'A' and c <= 'Z') c = 'a' + (c - 'A');
        most_freq = max(++m[c - 'a'], most_freq);
      }
    }

    for (char c = 'a'; c <= 'z'; c++) {
      if (m[c - 'a'] == most_freq) cout << c;
    }
    cout << '\n';
  }

  return 0;
}
