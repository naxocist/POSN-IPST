#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
int pre[N], post[N], in[N];

void f(int l, int r, int a, int b) {
  if(l > r) return;

  int nd = pre[l];
  if(r-l+1 == 1) {
    cout << nd << '\n';
    return;
  }

  l ++,  b --;
  for(int i=0; i<=r-l; ++i) {
    // [l, l+i], [l+i+1, r]
    // [a, a+i], [a+i+1, b];
    if(pre[l] == post[a+i]) {
      f(l,l+i,a,a+i); 
      cout << nd << '\n';
      f(l+i+1,r,a+i+1,b);
      return ;
    }
  }
  return ;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  for(int i=0; i<n; ++i) cin >> pre[i];
  for(int i=0; i<n; ++i) cin >> post[i];

  f(0,n-1,0,n-1);
  return 0;
}
