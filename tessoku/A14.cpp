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
    ll N, K;
    cin >> N >> K;

    ll A[N+1], B[N+1], C[N+1], D[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];
    for(ll i = 1; i <= N; i++) cin >> B[i];
    for(ll i = 1; i <= N; i++) cin >> C[i];
    for(ll i = 1; i <= N; i++) cin >> D[i];

    ll P[N*N+1];
    ll Q[N*N+1];
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= N; j++){
            P[(i-1)*N+j] = A[i]+B[j];
            Q[(i-1)*N+j] = C[i]+D[j];
        }
    }

    sort(P+1, P+N*N+1);
    sort(Q+1, Q+N*N+1);

    ll flag = false;
    for(ll i = 1; i <= N*N; i++){
        ll l = 1;
        ll r = N*N;
        while(l <= r){
            ll center = (l+r)/2;
            if(Q[center] == K-P[i]){
                flag = true;
                break;
            }
            else{
                if(Q[center] <  K-P[i]) l = center+1;
                else r = center - 1;
            }
        }
    }
    if(flag == true) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}