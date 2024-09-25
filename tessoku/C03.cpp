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
    ll D, X;
    cin >> D >> X;
    ll A[D+1];
    ll sum[D+1];
    sum[1] = X;
    for(ll i = 2; i <= D; i++) {
        cin >> A[i];
        sum[i] = sum[i-1] + A[i];
    }

    ll Q;
    cin >> Q;
    for(ll i = 1; i <= Q; i++){
        ll S, T;
        cin >> S >> T;
        if(sum[S] > sum[T]) cout << S << endl;
        if(sum[S] < sum[T]) cout << T << endl;
        if(sum[S] == sum[T]) cout << "Same" << endl;
    }
    return 0;
}