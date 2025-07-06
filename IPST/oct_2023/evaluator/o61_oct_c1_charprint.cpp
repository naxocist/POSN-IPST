#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 3;
using ll = long long int;
queue<int> idx[30];
ll fw[N], m;

int sum(int i) {
	ll s = 0;
	for(;i;i-=i&-i) {s += fw[i];}
	return s;
}

void upd(int i, int x) {
	for(;i<=m; i+=i&-i) {fw[i] += x; }
	return ;
}


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;
	string a, b; cin >> a >> b;
	m = a.size();
	for(int i=1; i<=m; ++i) {
		idx[a[i-1] - 'a'].push(i);
		upd(i, 1);
	}

	ll res = 0;
	for(char c : b) {
		int i = c-'a';
		if(idx[i].empty()) {
			cout << -1; 
			return 0;
		}
		int d = idx[i].front(); idx[i].pop();
		res += sum(d);
		if(n == 1) upd(d, -1);
	}
	cout << res;
	return 0;
}