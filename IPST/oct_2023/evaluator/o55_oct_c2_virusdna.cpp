#include <bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "-------------\n";
#define all(x) x.begin(), x.end()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int N = 1e6 + 3;
int gar[N], num[N], n, m;

void upd(int i, int x, int *fw) {
	for(;i<N;i+=lsb(i)) fw[i] += x;
	return ;
}

int qry(int i, int *fw, int s = 0) {
	for(;i>0;i-=lsb(i)) s += fw[i];
	return s;
}

int nth(int x) {
	int l = 1, r = n;
	while(l < r) 
	{
		int md = l + (r-l)/2;
		int a = qry(md, num); 
		int b = qry(md, gar);
		if(a == x) return md;
		if(a + qry(md, gar-1)<x and a+b>=x) return -md;

		if(a + b > x) r = md - 1;
		else l = md + 1;
	}
	if(qry(l, num) == x) return l;
	return -l;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;

    for(int i=1; i<=n; ++i) upd(i, 1, num);

    while(m--) {
    	char c; cin >> c;
    	int x, y;
    	if(c == 'd') 
    	{
    		cin >> x; x ++;
    		x = nth(x);
    		if(x < 0) upd(-x, -1, gar);
    		else upd(x, -1, num);
    	}
    	else if(c == 'g')
    	{
    		cin >> x; x ++;
    		x = nth(x);
    		upd(abs(x), 1, gar);
    	}
    	else 
    	{
    		int x, y; cin >> x >> y;
    		int nm = qry(y, num) - qry(x-1, num);
    		int gr = qry(y, gar) - qry(x-1, gar);
    		cout << y-x+1-nm+gr << '\n';
    	}
    }
    return 0;
}
