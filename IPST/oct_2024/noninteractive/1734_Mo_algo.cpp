#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define pb emplace_back

const int N = 2e5 + 3;
int ar[N];

struct qry { int l, r, idx; };

int bsz = 0;
bool cmp(qry a, qry b) {
  int ba = a.l/bsz, bb = b.l/bsz;
  if(ba != bb) return ba < bb;
  return a.r < b.r;
}

unordered_map<int, int> freq;
int cnt;
void add(int x) {
  if(freq[x] == 0) cnt ++;
  freq[x] ++;
}

void remove(int x) {
  if(freq[x] == 1) cnt --;
  freq[x] --;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;
  for(int i=1; i<=n; ++i) cin >> ar[i];
  bsz = (int)sqrt(n)

  vector<qry> v;
  for(int i=1; i<q; ++i){
    int l, r; cin >> l >> r;
    qry t; t.l=l,t.r=r,t.idx=i;
    v.pb(t);
  }
  
  sort(v.begin(), v.end(), cmp);
  vector<int> res(q);
  int cl = 1, cr = 0;
  for(qry x : v) {
    while(cl > x.l) cl --, add(ar[cl]);
    while(cr < x.r) cr ++, add(ar[cr]); 

    while(cl < x.l) remove(ar[cl]), cl ++;
    while(cr > x.r) remove(ar[cr]), cr --;
    res[x.idx] = cnt;
  }

  for(auto x : res) cout << x << ln;
  return 0;
}
