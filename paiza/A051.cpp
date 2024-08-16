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
    ll s[H+1][W+1];
    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++) cin >> s[i][j];
    }

    ll dp[H+1][W+2]; //dp[i][j]で(i,j)が倒されたとき最も高い点数．W+2としているのは左右にバッファをつけて条件分岐を少なくするため
    for(ll i = 1; i <= H; i++){
        for(ll j = 0; j <= W+1; j++){
            dp[i][j] = 0;
        }
    }



    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            if(i == 1) dp[i][j] = s[i][j];
            else dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i-1][j+1])) + s[i][j];
        }
    }
    ll val = 0;
    for(ll j = 1; j <= W; j++){
        val = max(val, dp[H][j]);
    }
    cout << val << endl;
    return 0;
}