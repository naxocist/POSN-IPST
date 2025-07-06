#include "sum_product.h"
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    cout << sum_product(n, a) << "\n";
}
