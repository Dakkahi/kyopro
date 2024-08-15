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
    ll A[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];

    ll dp[N+1][N+1]; //dp[i][j]でi段目の左からj番目

    for(ll i = N; i >= 1; i--){
        for(ll j = 1; j <= N; j++){
            if(i == N) dp[i][j] = A[j];
            else{
                if(i%2 == 1) dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]);
                else dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
    }
    cout << dp[1][1] << endl;
    return 0;
}