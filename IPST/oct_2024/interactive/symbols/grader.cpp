#include "symbols.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  std::cin >> n >> q;
  explore_site(n, q);
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    std::cout << retrieve_notes(l, r) << std::endl;
  }
  return 0;
}
