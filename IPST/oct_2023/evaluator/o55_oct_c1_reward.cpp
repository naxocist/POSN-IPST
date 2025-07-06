#include <bits/stdc++.h>
using namespace std;

int main() {

	int l = 1, r = 0;
	int n, k; scanf("%d%d", &n, &k);
	vector<int> v(n);
	for(int i=0; i<n; ++i) scanf("%d", &v[i]), r = max(r, v[i]);

	while(l < r) {
		int md = l + (r - l)/2;

		int d = 0;
		for(int x : v) {
			d += ((x - 1) / md) + 1;
		}

		if(d <= k) r = md;
		else l = md + 1;
	}

	printf("%d", l);

	return 0;
}