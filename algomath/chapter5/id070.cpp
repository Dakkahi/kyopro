#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
using ll = long long;

ll check_num(ll a, ll b, ll c, ll d, ll X, ll Y, ll cnt){
    if(a<=X && X <= c && d<= Y && Y <= b) cnt++;
    return cnt;
}

int main(){
    ll N, K;
    cin >> N >> K;
    ll x[N+1], y[N+1];
    for(ll i = 1; i <= N; i++) cin >> x[i] >> y[i];

    ll ans = (1LL << 62);

    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= N; j++){
            for(ll k = 1; k <= N; k++){
                for (ll l = 1; l <= N; l++){
                    ll a = x[i];
                    ll b = y[j];
                    ll c = x[k];
                    ll d = y[l];
                    ll cnt = 0;
                    for(ll m = 1; m <= N; m++){
                        cnt = check_num(a, b, c, d, x[m],y[m], cnt);
                    }
                    if(cnt >= K) {
                        ll area = 1LL*(c-a)*(b-d);
                        ans = min(ans, area);
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}