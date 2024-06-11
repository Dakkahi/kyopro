#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
using ll = long long;

int main(){
    ll H, W;
    cin >> H >> W;
    ll A[H*W+1], ans[H*W+1];
    for(ll i = 1; i <= H*W; i++) {
        cin >> A[i];
        ans[i] = 0;
    }

    ll r[H+1];
    ll c[W+1];
    for(ll i = 1; i <= H; i++){
        r[i] = 0;
        for(ll j = 1; j <= W; j++){
            r[i] += A[(i-1)*W+j];
        }
    }

    for(ll i = 1; i <= W; i++){
        c[i] = 0;
        for(ll j = 1; j <= H; j++){
            c[i] += A[(j-1)*W+i];
        }
    }

    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            ans[(i-1)*W+j] = r[i] + c[j] - A[(i-1)*W+j];
            cout << ans[(i-1)*W+j] << " ";
        }
        cout << endl;
    }
    return 0;
}