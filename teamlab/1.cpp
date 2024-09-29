#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ll N = 42;
    for(ll i = 1; i <= 30; i++){
        ll prod = N/2;
        N += prod;
    }
    cout << N << endl;
    return 0;
}