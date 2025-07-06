#include "rescue.h"
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
#define div cout << "============\n";
using pi = pair<int, int>;
#define pb emplace_back
const int N = 2e3 + 4;
int fw[N][N];
vector<int> x, y;
vector<pi> v;
int n, q;
int mn;
bool no[N];

void upd(int x, int y, int v) {
    for(int i=x; i<N; i+=i&-i) {
        for(int j=y; j<N; j+=j&-j) fw[i][j] += v;
    }
}

int qry(int x, int y){
    int s = 0;
    for(int i=x; i>0; i-=i&-i) {
        for(int j=y; j>0; j-=j&-j) s += fw[i][j];
    }
    return s;
}

int get(int a, int b, int c, int d) {
    return qry(c, d) - qry(a-1, d) - qry(c, b-1) + qry(a-1, b-1);
}

void init_rescue(int N, int Q, std::vector<int> X, std::vector<int> Y){
    x = X;
    y = Y;
    n = N, q = Q;
    for(int i=0; i<n; ++i) {
        upd(X[i]+1, Y[i]+1, 1);
    }

}

int answer_query(int a, int b, int c, int d)
{   
    a++,b++,c++,d++;
    int g = get(a, b, c, d);
    if(g) return -g;

    int ret = INT_MAX;
    int l = 1, r = a-1, res = -1;
    while(l <= r) {
        int md = l + (r-l)/2;
        if(get(md, b, a, d)) res = md, l = md + 1;
        else r = md - 1; 
    }
        // cout << abs(a-res) << endl;

    if(res!=-1)ret=min(ret,abs(a-res));

    l = c+1, r = 2001, res = -1;
    while(l <= r) {
        int md = l + (r-l)/2;
        if(get(c, b, md, d)) res = md, r = md - 1;
        else l = md + 1;
    }
    // cout << abs(c-res) << endl;
    if(res!=-1)ret=min(ret,abs(c-res));

    l = 1, r = b-1, res = -1;
    while(l <= r) {
        int md = l + (r-l)/2;
        if(get(a, md, c, b)) res = md, l = md + 1;
        else r = md - 1; 
    }
    if(res!=-1)ret=min(ret,abs(b-res));
    l = d+1, r = 2001, res = -1;
    while(l <= r) {
        int md = l + (r-l)/2;
        if(get(a, d, c, md)) res = md, r = md - 1;
        else l = md + 1; 
    }

    if(res!=-1)ret=min(ret,abs(d-res));

    return (ret == INT_MAX ? 0 : ret);
}

void cancel_request(int R)
{
    upd(x[R]+1, y[R]+1, -1);
}
