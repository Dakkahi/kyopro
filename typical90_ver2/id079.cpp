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
    ll A[H+1][W+1], B[H+1][W+1], C[H+1][W+1];
    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++) cin >> A[i][j];
    }
    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++) {
            cin >> B[i][j];
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    ll cnt = 0;
    for(ll i = 1; i <= H-1; i++){
        for(ll j = 1; j <= W; j++){
            ll val = C[i][j];
            cnt += abs(val);
            C[i+1][j] -= val;
            C[i][j+1] -= val;
            C[i+1][j+1] -= val;
        }
    }
    if(C[H-1][W] != 0 || C[H][W-1] != 0 || C[H][W] != 0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
        cout << cnt << endl;
    }
    return 0;
}