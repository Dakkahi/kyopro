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
    ll N;
    cin >> N;
    ll A, B;
    cin >> A >> B;
    bool dp[N+1];
    for(ll i = 1; i <= N; i++) dp[i] = false;
    dp[0] = true;

    ll a = min(A, B);
    ll b = max(A, B);

    for(ll i = a; i <= N; i++){
        if(i < b){
            if(dp[i-a] == true) dp[i] = true;
        }
        else{
            if(dp[i-a] == true || dp[i-b] == true) dp[i] = true;
            if(i + b >= N && dp[i] == true) dp[N] = true;
        }
    }

    ll cnt = 0;
    for(ll i = 1; i <= N; i++){
        if(dp[i] == false) cnt++;
    }

    cout << cnt << endl;
    return 0;
}