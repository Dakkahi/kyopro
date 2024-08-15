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
    char S[H+1][W+1];
    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++) cin >> S[i][j];
    }

    ll cnt = 0;
    for(ll i = 2; i <= H-1; i++){
        for(ll j = 2; j <= W-1; j++){
            if(S[i][j] == '#'){
                if(S[i+1][j] == '#' &&  S[i-1][j] == '#' && S[i][j+1] == '#' && S[i][j-1] == '#') cnt ++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}