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
    string S, T;
    cin >> S >> T;
    ll n = S.length();
    ll m = T.length();

    ll dp[n+1][m+1];
    for(ll j = 0; j <= m; j++) dp[0][j] = j;
    for(ll i = 0; i <= n; i++) dp[i][0] = i;

    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            if(S[i-1] == T[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1]+1));
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}