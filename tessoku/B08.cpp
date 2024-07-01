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
    ll N;
    cin >> N;

    ll s[1501][1501];
    for(ll i = 0; i <= 1500; i++){
        for(ll j = 0; j <= 1500; j++) s[i][j] = 0;
    }

    ll X, Y;
    for(ll i = 1; i <= N; i++) {
        cin >> X >> Y;
        s[X][Y] += 1;
    }

    for(ll i = 1; i <= 1500; i++){ //まずは縦に足す
        for(ll j = 1; j <= 1500; j++){
            s[i][j] = s[i-1][j] + s[i][j];
        }
    }

    for(ll i = 1; i <= 1500; i++){ //次に横に足す
        for(ll j = 1; j <= 1500; j++){
            s[i][j] = s[i][j-1] + s[i][j];
        }
    }



    ll Q;
    cin >> Q;
    for(ll i = 1;i <= Q; i++){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll ans = s[c][d] - s[a-1][d] - s[c][b-1] + s[a-1][b-1];
        cout << ans << endl;
    }

    return 0;
}