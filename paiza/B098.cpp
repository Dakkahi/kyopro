#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    ll N, M, T, K;
    cin >> N >> M >> T >> K;
    ll a[M+1][N+1];
    for(ll i = 1; i <= M; i++){
        for(ll j = 1; j <= N; j++) cin >> a[i][j];
    }

    for(ll j = 1; j <= N; j++){
        ll sum = 0;
        ll cnt = 0;
        for(ll i = 1; i <= M-T+1; i++){
            if(i == 1){
                for(ll t = 0; t < T; t++) {
                    sum += a[i+t][j];
                    if(cnt == 0 && sum >= K) cnt = i+t;
                }
            }else{
                sum -= a[i-1][j];
                sum += a[i+T-1][j];
                if(cnt == 0 && sum >= K) cnt = i+T-1;
            }
        }
        if(cnt == 0) cout << "no" << " " << cnt << endl;
        else cout << "yes" << " " << cnt << endl;
    }
    return 0;
}