#include <bits/stdc++.h>
using namespace std;


struct node {
  int key;
  node *l, *r;

  node(int key): key(key), l(nullptr), r(nullptr) {}; 
};

using pnode = node*;


void insert(pnode &cur, int k) {
  if(!cur) cur = new node(k); 
  else insert(k < cur->key ? cur->l : cur->r, k);
}

void find(pnode &res, pnode cur, int k) {
  if(!res or res->key == k) return void(res = cur);
  
  find(res, k < res->key ? cur->l : cur->r, k);
}

void del(pnode &cur, int k) {
  if(!cur) return ;

  if(k < cur->key) del(cur->l, k);
  else if(k > cur->key) del(cur->r, k);
  else {
    pnode &ch = cur->l ? cur->l : cur->r;
    if(!ch) cur = nullptr;
    else {
      cur->key = ch->key;
      del(ch, ch->key);
    }
  }
}

void inOrder(pnode cur) {
  if(!cur) return ;
  inOrder(cur->l);
  cout << cur->key << ' ';
  inOrder(cur->r);
}

int main() {
  int n; cin >> n;
  pnode t = nullptr;

  for(int i=0; i<n; ++i) {
    int x; cin >> x;
    insert(t, x);
  }

  inOrder(t); cout << endl;
  del(t, 30);
  inOrder(t);
  return 0;
}
