#include <bits/stdc++.h>
using namespace std;

const int N = 303;
int ar[N][N], in[N];

int main() {
  int n, t; cin >> n >> t;
  for(int i=1; i<=n; ++i) 
    for(int j=1; j<=n; ++j) 
      cin >> ar[i][j];

  for(int i=1; i<=n; ++i) {
    for(int j=i+1; j<=n; ++j) {
      bool direct = true;
      for(int k=1; k<=n; ++k) {
        if(k == i or k == j) continue ;
        if(ar[i][k] + ar[k][j] == ar[i][j]) direct = false;  
      }
      if(direct) in[i]++, in[j]++;
    }
  }

  for(int i=1; i<=n; ++i) {
    if(in[i] >= 3) {
      cout << i << '\n';
      if(t == 2) cout << in[i];
      exit(0);
    }
  }
  return 0;
}
