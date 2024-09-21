#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long; 



int main(){
    ll N;
    cin >> N;
    ll X[N+1], P[N+1], P_sum[N+1];
    P_sum[0] = 0;
    for(ll i = 1; i <= N; i++) cin >> X[i];
    for(ll i = 1; i <= N; i++) {
        cin >> P[i];
        P_sum[i] = P_sum[i-1] + P[i];
    }

    ll Q;
    cin >> Q;
    for(ll q = 1; q <= Q; q++){
        ll L, R;
        cin >> L >> R;
        ll l = lower_bound(X+1, X+N+1, L) - X;
        ll r = upper_bound(X+1, X+N+1, R) - X;
        if(l == r) cout << 0 << endl;
        else{
            r -= 1;
            cout << P_sum[r] - P_sum[l-1] << endl;
        }
    }
    return 0;
}