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
    ll N;
    cin >> N;
    ll A[N+1][7];
    ll B[N+1];
    for(ll i = 1; i <= N; i++){
        B[i] = 0;
        for(ll j = 1; j <= 6; j++) {
            cin >> A[i][j];
            B[i] += A[i][j];
            }
    }

    ll mod = 1e9+7;

    ll prod = 1;
    for(ll i = 1; i <= N; i++){
        prod *= B[i];
        prod %= mod;
    }

    cout << prod << endl;
    return 0;
}