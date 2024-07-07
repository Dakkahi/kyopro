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
    ll N, S;
    cin >> N >> S;
    ll A[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];

    sort(A+1, A+N+1);

    bool dp[N+1][S+1]; //dp[i][j]でi枚目までのカードで合計がjとなるようなものの最大値
    dp[0][0] = true;

    for(ll j = 1; j <= S; j++) dp[0][j] = false;

    for(ll i = 1; i <= N; i++){
        for(ll j = 0; j <= S; j++){
            if(j < A[i]) dp[i][j] = dp[i-1][j];
            else{
                if(dp[i-1][j] == true || dp[i-1][j-A[i]] == true) dp[i][j] = true;
                else dp[i][j] = false;
            }
        }
    }
    for(ll i = 1; i <= N; i++){
        if(dp[i][S] == true){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}