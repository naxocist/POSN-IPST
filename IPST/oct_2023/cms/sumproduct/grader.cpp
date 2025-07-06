#include "sum_product.h"
#include <bits/stdc++.h>
using namespace std;
#include "sum_product_sub1.cpp"

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    cout << sum_product(n, a) << "\n";
}
