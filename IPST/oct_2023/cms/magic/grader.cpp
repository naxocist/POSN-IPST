#include "magic.h"
#include <bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using T = tuple<int, int, int>;
const int N = 2e5 + 3;
vector<pi> adj[N];
int need[N];
bool broke[N];

void dfs(int u) {
	for(auto e : adj[u]) {
		int v, i; tie(v, i) = e;
		if(broke[i]) {
			if(need[v] <= need[u] + 1) continue ;
			need[v] = need[u] + 1;
			dfs(v);
		}else {
			if(need[v] <= need[u]) continue ;
			need[v] = need[u];
			dfs(v);
		}
	}
	return ;
}


vector<int> magic(int N, int M,int Q, vi U, vi V, vector<vi> q){

	for(int i=0; i<N; ++i) need[i] = 11;
		for(int i=0; i<M; ++i) {
			adj[V[i]].pb(U[i], i);
		}

	for(auto x : q) if(x[0]==0) broke[x[1]] = 1;
		need[0] = 0;
	dfs(0);
	reverse(all(q));
	vi res;
	for(auto x : q) {
		if(x[0] == 0) {
			int no = x[1];
			broke[no] = 0;
			if(need[V[no]]<need[U[no]]){
				need[U[no]] = need[V[no]];
				dfs(U[no]);
			}
			res.pb(-1);
		}else {
			res.pb(need[x[1]] <= x[2]);
		}
	}
	reverse(all(res));
	return res;
}


int main() {
		int Q,N,M,a,b,t;
		vector<int>U,V,user_ans;
		vector<vector<int> >q;
		assert(scanf("%d %d %d",&N,&M,&Q)==3);
		for(int i=0;i<M;i++){
		assert(scanf("%d %d",&a,&b)==2);
		U.push_back(a);
		V.push_back(b);
		}
		for(int i=0;i<Q;i++){
		vector<int>query;
		assert(scanf("%d",&t)==1);
		query.push_back(t);
		if(t==0){
		assert(scanf("%d",&a)==1);
			query.push_back(a);
		}
		else{
			assert(scanf("%d %d",&a,&b)==2);
				query.push_back(a);
				query.push_back(b);
			}
			q.push_back(query);
		}
		user_ans = magic(N, M, Q, U, V, q);
		for(auto x : user_ans) cout << x << ' '; cout << endl;
			for(int i=0;i<Q;i++){
				if(q[i][0]==1){
					if(user_ans[i]==0)printf("No\n");
					else printf("Yes\n");
				}
			}
}
