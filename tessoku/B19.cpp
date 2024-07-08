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
    ll N, W;
    cin >> N >> W;
    ll w[N+1], v[N+1];
    ll val_sum = 0;
    for(ll i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
        val_sum += v[i];
    }


    ll dp[N+1][val_sum+1]; //dp[i][j]でi番目までの品を価値j以下に収まるようにしたときの質量の最小値
    dp[0][0] = 0;
    for(ll j = 1; j <= val_sum; j++) dp[0][j] = W+1;

    for(ll i = 1; i <= N; i++){
        for(ll j = 0; j <= val_sum; j++){
            if(j < v[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]] + w[i]);
            
        }
    }

    //価値の最大値を求める
    ll val = 0;
    for(ll j = 1; j <= val_sum; j++){
        if(dp[N][j] <= W) val = j;
    }
    cout << val << endl;
    return 0;
}