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
    ll A[H*W+1], B[H*W+1], C[H*W+1];
    for(ll i = 1; i <= H*W; i++) cin >> A[i];
    for(ll i = 1; i <= H*W; i++) {
        cin >> B[i];
        C[i] = B[i] - A[i];
    }
    ll cnt = 0;
    for(ll i = 1; i <= (H-1); i++){
        for(ll j = 1; j <= (W-1); j++){
            ll num = C[(i-1)*W + j];
            C[(i-1)*W + j] = 0;
            C[(i-1)*W + j+1] -= num;
            C[(i-1+1)*W + j] -= num;
            C[(i-1+1)*W + j+1] -= num;
            cnt += abs(num);
        }
    }
    bool flag = true;
    for(ll i = 1; i <= H*W; i++){
        if(C[i] != 0) {
            flag = false;
            break;
        }
    }
    if(flag == true) {
        cout << "Yes" << endl;
        cout << cnt << endl;
    }
    else cout << "No" << endl;
    return 0;
}