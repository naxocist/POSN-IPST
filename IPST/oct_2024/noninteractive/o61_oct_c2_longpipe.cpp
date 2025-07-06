
#include <bits/stdc++.h>
using namespace std;

using ll = long long; 
ll mod = 1e9 + 7;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;

  ll b[6][6] = {
    {1,1,0,0,0,1},
    {2,1,0,0,0,0},
    {1,0,0,0,0,0},
    {0,1,0,0,0,0},
    {1,1,0,0,1,1},
    {0,0,0,0,1,0}
  };

  ll nw[6] = {1, 1, 0, 0, 1, 0};
  n ++;
  while(n > 0){
    if(n & 1) {
      ll nxt[6];
      for(int i=0; i<6; ++i) nxt[i] = 0;
      for(int k=0; k<6; ++k) { 
        for(int i=0; i<6; ++i) {
          nxt[i] += b[i][k]*nw[k];
          nxt[i] %= mod;
        }
      }
      for(int i=0; i<6; ++i) nw[i] = nxt[i];
    }


    ll res[6][6] = {0};

    for(int k=0; k<6; ++k) {
      for(int i=0; i<6; ++i) {
        for(int j=0; j<6; ++j) {
          res[i][j] += b[i][k]*b[k][j]; 
          res[i][j] %= mod;
        }
      }
    }

    for(int i=0; i<6; ++i) for(int j=0; j<6; ++j) b[i][j] = res[i][j];
    n/=2;
  }

  cout << nw[1] << '\n';
  return 0;
}
