#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ll N, S;
    cin >> N >> S;
    ll A[N+1], B[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i] >> B[i];

    bool dp[N+1][S+1]; //dp[i][j]でi日目まででj円を作成することができるか
    for(ll i = 0; i <= N; i++){
        for(ll j = 0; j <= S; j++) dp[i][j] = false;
    }

    dp[0][0] = true;
    for(ll j = 1; j <= S; j++) dp[0][j] = false;
    for(ll i = 1; i <= N; i++) dp[i][0] = false;

    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= S; j++){
            if((A[i] <= j && dp[i-1][j-A[i]] == true) || (B[i] <= j && dp[i-1][j-B[i]] == true)) dp[i][j] = true;
            else dp[i][j] = false;
        }
    }
    if(dp[N][S] == false) cout << "Impossible" << endl;
    else{
        stack<char> Q;
        ll val = S;
        for(ll i = N; i >= 1; i--){
            if(val >= A[i] && dp[i-1][val-A[i]] == true) {
                Q.push('A');
                val -= A[i];
            }
            else {
                Q.push('B');
                val -= B[i];
            }
        }
        while(!Q.empty()){
        cout << Q.top();
        Q.pop();
    }
    }
    return 0;
}