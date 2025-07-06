#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> s;
  int q; cin >> q;
  while(q--) {
    char c; int x; cin >> c >> x;
    if(c == 'I') s.insert(x);
    else if(c == 'O') cout << s.order_of_key(x) << '\n';
    else cout << *s.find_by_order(x) << '\n';
  }
}
