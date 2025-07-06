#ifndef __VILLAGE_H_
#define __VILLAGE_H_

#include <vector>

void init_village(int N, int M, int Q, std::vector<int> U, std::vector<int> V, std::vector<int> W);
std::vector<std::vector<int>> move_in(int K, std::vector<int> X, std::vector<int> Y);

#endif