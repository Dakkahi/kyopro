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

class SegTree{
    public:
    ll dat[100001];
    ll siz = 1;
    void init(ll N){
        while(siz <= N) siz *= 2;
        for(ll i = 0; i < 2*siz; i++) dat[i] = -(1LL << 60);
    }

    void update(ll pos, ll x){
        pos += siz;
        dat[pos] = x;
        while(pos > 1){
            pos /= 2;
            dat[pos] = max(dat[2*pos], dat[2*pos+1]);
        }
    }

    ll query(ll l, ll r, ll a, ll b, ll u){
        if(r <= a || b <= l) return -(1LL << 60);
        if(l <= a && b <= r) return dat[u];
        ll m = (a+b)/2;
        ll ansL = query(l, r, a, m, 2*u);
        ll ansR = query(l, r, m, b, 2*u+1);
        return max(ansL, ansR);
    }

    ll max_val(ll l, ll r){
        return query(l, r, 0, siz, 1);
    }

};

int main(){
    ll W, N;
    cin >> W >> N;
    ll L_sum = 0;
    ll R_sum = 0;
    ll L[N+1], R[N+1], V[N+1];
    for(ll i = 1; i <= N; i++) {
        cin >> L[i] >> R[i] >> V[i];
        L_sum += L[i];
        R_sum += R[i];
    }

    // if(L_sum <= W && W <= R_sum){
    //     cout << -1 << endl;
    //     return 0;
    // }

    ll dp[N+1][W+1]; //dp[i][j]で「i番目までの香辛料を使って料理を作り，香辛料をjだけ使って価値を最大化する」
    for(ll i = 0; i <= N; i++){
        for(ll j = 0; j <= W; j++) dp[i][j] = -(1LL << 60);
    }

    
    SegTree Z[N+1];
    for(ll i = 0; i <= N; i++) Z[i].init(W+2);
    dp[0][0] = 0;
    Z[0].update(0,0);

    for(ll i = 1; i <= N; i++){
        for(ll j = 0; j <= W; j++) dp[i][j] = dp[i-1][j];
            for(ll j = 0; j <= W; j++){
                ll cl = max((ll)0, j-R[i]);
                ll cr = max((ll)0, j - L[i] + 1);
                if(cl == cr) continue;
                ll M = Z[i-1].max_val(cl, cr);
                if(M != -(1LL << 60)) dp[i][j] = max(M + V[i], dp[i][j]);
            
            }
        for(ll j = 0; j <= W; j++) Z[i].update(j, dp[i][j]);
    }
    //cout << dp[N][W] << endl;
    if(dp[N][W] == -(1LL << 60))cout << -1 << endl;
    else cout << dp[N][W] << endl;
    return 0;
}