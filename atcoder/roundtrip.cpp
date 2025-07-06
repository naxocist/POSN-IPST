#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3;
int dsu[N];
int n, m;

int f(int i, int j) {
  return m * i + j;
}

int par(int u) {
  return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}

void un(int a, int b, int x, int y) {
  int h = f(a, b), k = f(x, y);
  int s = par(h), z = par(k);
  dsu[s] = z;
}

bool chk(int i, int j) {
  return i >= 0 && j >= 0 && i < n && j < m;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> n >> m;

  int a, b;
  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    s += x;
    for (int j = 0; j < m; ++j) {
      if (x[j] == 'S')
        a = i, b = j;
    }
  }
  for (int i = 0; i < n * m; ++i)
    dsu[i] = i;

  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[f(i, j)] == '.' && s[f(i + 1, j)] == '.')
        un(i, j, i + 1, j);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m - 1; ++j) {
      if (s[f(i, j)] == '.' && s[f(i, j + 1)] == '.')
        un(i, j, i, j + 1);
    }
  }

  int t[] = {1, 0, -1, 0, 1};
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (i == j)
        continue;
      int h = a + t[i], k = b + t[i + 1];
      int s = a + t[j], z = b + t[j + 1];
      if (!chk(h, k) || !chk(s, z))
        continue;
      if (par(f(h, k)) == par(f(s, z))) {
        printf("Yes");
        return 0;
      }
    }
  }

  printf("No");
  return 0;
}

/*
4 4
S...
....
....
....
*/
