#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

long long N, W, w[109], v[109];
long long dp[109][100009];

int main(){
    cin >> N >> W;
    for(int i = 1; i <= N; i++) cin >> w[i] >> v[i];
    dp[0][0] = 0;
    for(int i = 1; i <= W; i++) dp[0][i] = -(1LL << 60);

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= W; j++){
            if(j < w[i]) dp[i][j] = dp[i-1][j];
            if(j >= w[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
        }
    }

    long long ans = 0;
    for(int i = 0; i <= W; i++) ans = max(ans, dp[N][i]);
    cout << ans << endl;
    return 0;
}