#include "longest.h"
#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>; 


std::vector<std::pair<int,int>> longest(int N) {
    vector<pi> ret;
    ret.pb(0,0); ret.pb(0,1);    
    int h=0,t=1;

    if(N>=3){
        if(find(h, t, 2)) ret.pb(2, t), h=2;
        else ret.pb(2, h), t=2;
    }
    for(int i=3; i<N; ++i){
        if(find(t, h, i)) {
            if(find(i, t, h)) ret.pb(h, t);
            else ret.pb(i, h),t=i;
        }else {
            if(find(i, h, t)) ret.pb(h, t);
            else ret.pb(i, t), h=i;
        }
    }
    return ret;
}