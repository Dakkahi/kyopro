#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    ll C[N+1], P[N+1];
    ll sum_1[N+1];
    ll sum_2[N+1];
    for(ll i = 1; i <= N; i++) {
        cin >> C[i] >> P[i];
        sum_1[i] = 0;
        sum_2[i] = 0;
    }

    ll Q;
    cin >> Q;
    ll L[Q+1], R[Q+1];
    for(ll i = 1; i <= Q; i++) cin >> L[i] >> R[i];

    for(ll i = 1; i <= N; i++){
        if(C[i] == 1){
            sum_1[i] = sum_1[i-1] + P[i];
            sum_2[i] = sum_2[i-1];
        }
        if(C[i] == 2){
            sum_2[i] = sum_2[i-1] + P[i];
            sum_1[i] = sum_1[i-1];
        }
    }
    for(ll i = 1; i <= Q; i++){
        ll ans_1 = sum_1[R[i]] - sum_1[L[i]-1];
        ll ans_2 = sum_2[R[i]] - sum_2[L[i]-1];
        cout << ans_1 << " " << ans_2 << endl;
    }
    return 0;
    
}