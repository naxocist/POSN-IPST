#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, k; cin >> n >> m >> k;
	int p = 0, s = 0, t = m;
	vector<int> v;
	while(t--) {
		int x; cin >> x;
		if(p) v.push_back(x - p - 1);
		p = x;
	}
	sort(v.begin(), v.end());
	for(int i=0; i<m-k; ++i) s += v[i];
	cout << s;
	return 0;
}