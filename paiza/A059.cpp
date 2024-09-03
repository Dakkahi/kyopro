#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
using ll = long long;

int main(){
    ll N, x;
    cin >> N >> x;
    ll w[N+1], r[N+1];
    for(ll i = 1; i <= N; i++) {
        cin >> w[i] >> r[i];
    }
    w[0] = 0;
    r[0] = 0;

    ll dp[N+1][x+1]; //dp[i][j]でi番目までの金魚を重さjまですくえるときの最大価値

    for(ll i = 0; i <= N; i++) dp[i][0] = 0;
    for(ll j = 0; j <= x; j++) dp[0][j] = 0;



    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= x; j++){
            if(j < w[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + r[i]);
        }
    }
    cout << dp[N][x-1] << endl;
    return 0;
}
