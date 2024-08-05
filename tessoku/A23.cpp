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
    ll N, M;
    cin >> N >> M;
    ll A[M+1][N+1];
    for(ll i = 1; i <= M; i++){
        for(ll j = 1; j <= N; j++) cin >> A[i][j];
    }
    ll dp[M+1][(1LL << N)];
    for(ll i = 0; i <= M; i++){
        for(ll j = 0; j <= (1LL << N); j++) dp[i][j] = 1e9; //dp[i][S]でクーポンiまで使う状況で集合Sの要素を全て買うのに最小で何枚使うか
    }
    dp[0][0] = 0;
    for(ll i = 1; i <= M; i++){
        for(ll j = 0; j < (1LL << N); j++){
            ll v = j;
            for(ll k = 1; k <= N; k++){
                if(A[i][k] == 1) v |= (1LL << (k-1)); //これでvのk-1ビット目を1にするという操作(OR演算)
            }
            dp[i][j] = min(dp[i][j], dp[i-1][j]); //クーポンiを使わない遷移
            dp[i][v] = min(dp[i][v], dp[i-1][j]+1);
        }
    }
    if(dp[M][(1LL << N)-1] == 1e9) cout << -1 << endl;
    else cout << dp[M][(1LL << N)-1] << endl;
    return 0;
    }
    
