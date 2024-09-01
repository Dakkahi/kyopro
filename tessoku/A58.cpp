#include <iostream>
#include <string>
#include <map>
#include<set>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

class SegmentTree{
    public:
    ll dat[300000], siz = 1;

    void init(ll N){
        siz = 1;
        while(siz < N) siz*= 2;
        for(ll i = 1; i <= siz*2; i++) dat[i] = 0;
    }

    void update(ll pos, ll x){
        pos = pos + siz - 1;
        dat[pos] = x;
        while(pos >= 2){
            pos /= 2;
            dat[pos] = max(dat[2*pos], dat[2*pos+1]);
        }
    }
    ll query(ll l, ll r, ll a, ll b, ll u){ // a, bは現在のセル番号. [l, r)の最大値を求める
        if(r <= a || b <= l) return -100000;//区間に入っていない場合
        if(l <= a && b <= r) return dat[u];
            ll m = (a+b)/2;
            ll ansL = query(l, r, a, m, u*2);
            ll ansR = query(l, r, m, b, u*2+1);
            return max(ansL, ansR);
    }
};

int main(){
    ll N, Q;
    cin >> N >> Q;
    SegmentTree Z;

    Z.init(N);
    for(ll i = 1; i <= Q; i++){
        ll q;
        cin >> q;
        if(q == 1){
            ll pos, x;
            cin >> pos >> x;
            Z.update(pos, x);
        }
        if(q == 2){
            ll l, r;
            cin >> l >> r;
            ll ans = Z.query(l, r, 1, Z.siz+1, 1);
            cout << ans << endl;
        }
    }
    return 0;
}