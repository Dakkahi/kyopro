#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    ll H, W, Y, X;
    cin >> H >> W;
    cin >> Y >> X;

    string m[H+1];
    for(ll i = 1; i <= H; i++) cin >> m[i]; 

    ll e, w, n, s;
    e = 0;
    w = 0;
    n = 0;
    s = 0;

    //行,列の合計を計算
    vector<ll> R(W+1, 0);
    vector<ll> C(H+1, 0);

    for(ll i = 1; i <= W; i++){
        for(ll j = 1; j <= H; j++){
            if(m[j][i-1] != '#'){
                R[i] += (m[j][i-1] - '0');
                C[j] += (m[j][i-1] - '0');
            }
        }
    }

    // for(ll i = 1; i <= H; i++){
    //     for(ll j = 1; j <= W; j++){
    //         if(m[i][j] != '#'){
    //             C[i] += (m[i][j] - '0');
    //         }
    //     }
    // }

    //N
    if(Y != 1){
        for(ll i = 1; i <= Y-1; i++){
            n += C[i];
        }
    }
    //S
    if(Y != H){
        for(ll i = Y+1; i <= H; i++){
            s += C[i];
        }
    }
    //W
    if(X != 1){
        for(ll i = 1; i <= X-1; i++){
            w += R[i];
        }
    }
    //E
    if(X != W){
        for(ll i = X+1; i <= W; i++){
            e += R[i];
        }
    }

    ll M = max({e,n,s,w});
    if(n == M) {
        cout << "N" << " " << M << endl;
        return 0;
    }
    if(e == M) {
        cout << "E" << " " << M << endl;
        return 0;
    }
    if(s == M) {
        cout << "S" << " " << M << endl;
        return 0;
    }
    if(w == M) {
        cout << "W" << " " << M << endl;
        return 0;
    }
}