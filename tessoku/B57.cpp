#include <iostream>
#include <string>
#include <map>
#include<set>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    ll N, K;
    cin >> N >> K;

    ll dp[31][N+1]; //dp[i][j]で「値がjのときに2^i回操作をした後の結果」を格納

    for(ll i = 0; i <= 30; i++){
        for(ll j = 0; j <= N; j++){
            if(i == 0){
                ll val = j;
                ll p = 10;
                dp[0][j] = j;
                while(val != 0){
                    dp[0][j] -= val%p;
                    val = val/p;
                }
                //cout << dp[0][j] << endl;
            }
            else{
                dp[i][j] = dp[i-1][dp[i-1][j]];
            }
        }
    }

    for(ll j = 1; j <= N; j++){
        ll val = j;
        for(ll k = 0; k <= 29; k++){
            if((K & (1LL << k)) != 0LL){
                val = dp[k][val];
            }
        }
        cout << val << endl;
    }
    return 0;
}