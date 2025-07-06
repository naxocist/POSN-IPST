#include "prison.h"
#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> devise_strategy(int N) {
	int x = 500;
	vector<vector<int>> res(x+1, vector<int>(N+1, 0));

	for(int j=1; j<=x; ++j) res[0][j] = j;

	for(int i=1; i<=x; ++i) {
		for(int j=0; j<=N; ++j) {
			res[i][j] = (i > j ? -1 : -2);
		}
	}

	return res;
}
