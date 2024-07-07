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
    ll h[N+1];
    for(ll i = 1; i <= N; i++) cin >> h[i];

    ll dp[N+1];
    for(ll i = 1; i <= N; i++){
        if(i == 1) dp[i] = 0;
        else if(i == 2) dp[i] = abs(h[i]-h[i-1]);
        else{
            dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));
        }
    }
    cout << dp[N] << endl;
    return 0;
}