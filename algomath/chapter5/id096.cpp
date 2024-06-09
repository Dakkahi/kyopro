#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;


int main(){
    ll N;
    cin >> N;
    ll T[N+1];
    for(ll i = 1; i <= N; i++) cin >> T[i];

    sort(T+1, T+N+1);
    ll sum = 0;
    for(ll i = 1; i <= N; i ++) sum += T[i];

    ll half = sum/2;

    //動的計画法で時刻tまでの最適な料理方法を考える。すなわち, iを超えないような最大の選び方dp[i]を考える
    ll dp[N+1][half+1]; //dp[i][j]:料理1からiまで選ぶとき、合計時間がjを超えないような最大時間

    dp[0][0] = 0;

    for(ll j = 1; j <= half; j++) dp[0][j] = 0;

    for(ll i = 1; i <= N; i++){
        for(ll j = 0; j <= half; j++){
            if(j < T[i]) dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-T[i]] + T[i]);
            }
        }
    }

    cout << sum - dp[N][half] << endl;
    return 0;


    

    

}