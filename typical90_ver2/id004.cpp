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
    ll H, W;
    cin >> H >> W;
    ll A[H+1][W+1];
    ll B[H+1][W+1];

    ll R_sum[H+1];
    ll C_sum[W+1];
    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++) {
            cin >> A[i][j];
            B[i][j] = 0;
        }
    }

    for(ll i = 1; i <= H; i++){
        R_sum[i] = 0;
        for(ll j = 1; j <= W; j++) R_sum[i] += A[i][j];
    }

    for(ll j = 1; j <= W; j++){
        C_sum[j] = 0;
        for(ll i = 1; i <= H; i++) C_sum[j] += A[i][j];
    }

    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            B[i][j] = R_sum[i] + C_sum[j] - A[i][j];
            if(j == W) cout << B[i][j] << endl;
            else cout << B[i][j] << " ";
        }
    }
    return 0;
}