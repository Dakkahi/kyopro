#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    ll N, Q;
    cin >> N >> Q;
    ll A;

    ll sum[N+1]; //i日目までの累積
    sum[0] = 0;
    for(ll i = 1; i <= N; i++) {
        cin >> A;
        sum[i] = sum[i-1] + A;
    }

    for(ll i = 1; i <= Q; i++){
        ll L, R;
        cin >> L >> R;
        cout << sum[R] - sum[L-1] << endl;
    }

    return 0;
}