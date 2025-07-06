#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 3;

struct node {
	int pr, key, rev, sz;
	node *l, *r;
	node(int x) : pr(rand()), key(x), rev(0), sz(1), l(NULL), r(NULL){}
} *root=NULL;

int sz(node *t) { return (t ? t->sz : 0); }

void push_up(node *&t) {
	if(!t) return ;
	t->sz = 1 + sz(t->l) + sz(t->r);
}
void push_down(node *&t) {
	if(!t) return ;
	if(t->rev) {
		t->rev = 0;
		swap(t->l, t->r);
		if(t->l) t->l->rev ^= 1;
		if(t->r) t->r->rev ^= 1;
	}
}

void split(node *t, node *&l, node *&r, int v) {
	if(!t) return void(l = r = NULL);
	push_down(t);
	if(sz(t->l) < v) split(t->r, t->r, r, v-sz(t->l)-1), l = t;
	else split(t->l, l, t->l, v), r = t;
	push_up(t);
}

void merge(node *&t, node *l, node *r) {
	if(!l || !r) return void(t = l ? l : r);
	push_down(l); push_down(r);
	if(l->pr > r->pr) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	push_up(t);
}

void print(node *t) {
	if(!t) return ;
	print(t->l);
	cout << t->key << ' ';
	print(t->r);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	srand(time(NULL));
	
	int n; cin >> n;
	for(int i=1; i<=n; ++i) {
		int x; cin >> x;
		merge(root, root, new node(x));
	}

	int cnt = 0;
	while(1) {
		
		node *a, *b;
		split(root, a, b, 1);
		int k = a->key;
		root = nullptr;
		merge(root, a, b);

		if(k == 1) break ;

		a = b = nullptr;
		split(root, a, b, k);
		a->rev ^= 1;
		merge(root, a, b);
		cnt ++;
	}
	cout << cnt;
	return 0;
}