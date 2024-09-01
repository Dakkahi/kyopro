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

class SegmentTree{
    public:
    ll dat[300001];
    ll siz = 1;

    void init(ll N){
        while(N > siz) siz *= 2;
        for(ll i = 1; i < siz*2; i++) dat[i] = 1000000000;
    }

    void update(ll pos, ll x){
        pos = pos + siz - 1;
        dat[pos] = x;
        while(pos >= 2){
            pos /= 2;
            dat[pos] = min(dat[2*pos], dat[2*pos+1]);
        }
    }

    ll query(ll l, ll r, ll a, ll b, ll u){
        if (r <= a || b <= l) return 1000000000;
        if (l <= a && b <= r) return dat[u];
        ll m = (a + b) / 2;
        ll ansL = query(l, r, a, m, 2*u);
        ll ansR = query(l, r, m, b, 2*u+1);
        return min(ansL, ansR);
    }
};

int main(){
    ll N, L, R;
    cin >> N >> L >> R;
    ll X[N+1];
    for(ll i  =1; i <= N; i++) cin >> X[i];

    SegmentTree Z;
    Z.init(N);
    Z.update(1, 0); // 初期化時に最初の要素を0にする

    for(ll i = 2; i <= N; i++){
        ll l = lower_bound(X+1, X+N+1, X[i] - R) - X;
        ll r = upper_bound(X+1, X+N+1, X[i] - L) - X;
        if (r > N) r = N + 1;

        ll x = Z.query(l, r, 1, Z.siz+1, 1);
        Z.update(i, x+1);
    }
    cout << Z.dat[N + Z.siz - 1] << endl;
    return 0;
}
