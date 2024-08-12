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
    ll H, W;
    cin >> H >> W;
    char c[H+1][W+1];
    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++) cin >> c[i][j];
    }

    ll dp[H+1][W+1];

    for(ll i = 0; i <= H; i++){
        for(ll j = 0; j <= W; j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(i == 1 && j == 1) dp[i][j] = 1;
            else{
                if(c[i][j] == '#') dp[i][j] = 0;
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
    }
    cout << dp[H][W] << endl;
    return 0;
}