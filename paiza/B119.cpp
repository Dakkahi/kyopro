#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    ll H, W;
    cin >> H >> W;
    ll s[H*W+1];
    for(ll i = 1; i <= H*W; i++) cin >> s[i];

    ll R, C;
    cin >> R >> C;
    string n[R+1];
    ll net[R*C+1];
    for(ll i = 1; i <= R; i++) cin >> n[i];

    for(ll i = 1; i <= R; i++){
        for(ll j = 0; j < C; j++){
            if(n[i][j] == '#') net[(i-1)*C + j+1] = 1;
            else net[(i-1)*C + j+1] = 0;
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= H-R+1; i++){
        for(ll j = 1; j <= W-C+1; j++){
            ll sum = 0;
            for(ll k = 1; k <= R; k++){
                for(ll r = 1; r <= C; r++){
                    sum += net[(k-1)*C + r]*s[(i-1+k-1)*W + j+r-1];
                }
            }
            //cout << sum << endl;
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;

}