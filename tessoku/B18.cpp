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
    bool flag = false;
    for(ll i = 1; i <= N; i++){
        if(dp[i][S] == true){
            flag = true;
            break;
        }
    }
    if(flag == false){
        cout << -1 << endl;
        return 0;
    }
    else{
        vector<ll> ans;
        ll i = N;
        ll j = S;
        while(1){
            if(j - A[i] >= 0 && dp[i-1][j-A[i]] == true){
                ans.push_back(i);
                j -= A[i];
            }
            i --;
            if(i == 0) break;
        }
        cout << ans.size() << endl;
        for(ll i = ans.size() - 1; i >= 0; i--){
            cout << ans[i] << " ";
        }
        return 0;
    }
}