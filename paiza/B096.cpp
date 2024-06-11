#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
#include<string>
using namespace std;
using ll = long long;

int main(){
    ll H, W;
    cin >> H >> W;
    char S[H*W+1];
    for(ll i = 1; i <= H*W; i++) cin >> S[i]; //(i-1)*W + j

    for(ll i = 1; i <=H; i++){
        for(ll j = 1; j <= W; j++){
            if(S[(i-1)*W + j] == '#'){
                for(ll k = 1; k <= W; k++){
                    if(S[(i-1)*W + k] == '.') S[(i-1)*W + k] = '*';
                }
                for(ll r = 1; r <= H; r++){
                    if(S[(r-1)*W + j] == '.') S[(r-1)*W + j] = '*';
                }
            }
        }
    }
    ll cnt = 0;
    for(ll i = 1; i<= H*W; i++){
        if(S[i] == '#' || S[i] == '*') cnt++;
    }
    cout << cnt << endl;
    return 0;
}
