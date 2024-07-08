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
    for(ll i = 1; i <= N; i++) cin >> w[i] >> v[i];

    ll dp[N+1][W+1]; //dp[i][j]でi番目までの品を重さj以下に収まるようにした時の最大価値とする
    dp[0][0] = 0;
    for(ll j = 1; j <= W; j++) dp[0][j] = 0;

    for(ll i = 1; i <= N; i++){
        for(ll j = 0; j <= W; j++){
            if(j < w[i]) dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }
    ll M = 0;
    for(ll j = 1; j <= W; j++){
        M = max(M, dp[N][j]);
    }
    cout << M << endl;
}