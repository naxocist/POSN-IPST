#ifndef HIGHWAY_H
#define HIGHWAY_H

#include <vector>

void init(int N, int Q, std::vector<int> A, std::vector<int> B, std::vector<int> C);

void update(int X, int Y, int Z);

long long query(int S, int T);

#endif