#include "snow.h"
#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
int n, m;
const int N = 1e5 + 3;
vector<int> adj[N];
bitset<N> vis;

vector<int> find_pair(int N, int M, vector<int>U, vector<int> V){
    n = N, m = M;
    vis.reset();
    int s = 0;
    vector<bool> v(M, 1);
    vector<int> res;
    int l = 0, r = M;
    while(l<=r) {
        int md = l +(r-l)/2;
        if()
    }
    // for(auto x : res) cout << x << ' '; cout <<endl;
    return res;
}