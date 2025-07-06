#include "guess.h"
#include <cstdio>
#include <cassert>
#include <utility>
#include <vector>
 
using namespace std;

static int n, m, k;
static int cnt;

char ask(const vector<pair<int, char>> V) {
  cnt++;
  if (V.empty()) {
    return 'X';
  }
  assert(V.begin()->first >= 0 and V.rbegin()->first < n);
  for (int i = 0; i < V.size(); ++i) {
    if (i) {
      assert(V[i-1].first < V[i].first);
    }
    if (k == 1) {
      assert(V[i].second == 'R');
    } else {
      assert(V[i].second == 'R' or V[i].second == 'B');
    }
  }
  vector<char> tmp(n);
  for (auto x : V) {
    tmp[x.first] = x.second;
  }
  for (int i = 0; i < n; ++i) {
    if (tmp[i] == 0) {
      tmp[i] = 'X';
      if (i != 0) {
        if (tmp[i - 1] == 'R' or tmp[i - 1] == 'B') {
          tmp[i] = 'C';
        }
      }
      if (i != n - 1) {
        if (tmp[i + 1] == 'R' or tmp[i + 1] == 'B') {
          tmp[i] = 'C';
        }
      }
    }
  }
  return tmp[m];
}

int main() {
	assert(scanf("%d %d %d", &n, &m, &k) == 3);
  assert(m >= 0 and m < n);
  assert(k == 1 or k == 2);
	int result = find_answer(n, k);
  if (result == m) {
    printf("Correct!\n");
  } else {
    printf("Wrong!\n");
  }
  printf("called %d times\n", cnt);
	return 0;
}
