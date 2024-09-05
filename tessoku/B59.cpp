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
        ll dat[600000];
        ll siz = 1;

    void init(ll N){
        while(siz < N){
            siz *= 2;
        }
        for(ll i = 1; i < 2*siz; i++) dat[i] = 0;
    }

    void update(ll pos, ll x){
        pos += siz - 1;
        dat[pos] = x;
        while(pos > 1){
            pos /= 2;
            dat[pos] = dat[2*pos] + dat[2*pos+1];
        }
    }

    ll query(ll l, ll r, ll a, ll b, ll u){
        if(r <= a || b <= l) return 0;
        if(l <= a && b <= r) return dat[u];
        ll mid = (a+b)/2;
        ll ansL = query(l, r, a, mid, 2*u);
        ll ansR = query(l, r, mid, b, 2*u+1);
        return ansL + ansR;
    }
};

int main(){
    ll N;
    cin >> N;
    ll A[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];

    SegTree Z;
    Z.init(N);
    ll ans = 0;

    for(ll i = 1; i <= N; i++){
        ans += Z.query(A[i]+1, N+1, 1, Z.siz + 1, 1); //既にA[i]より大きい要素がいくつ出てきたかをlogNで調べている
        Z.update(A[i], 1); //A[i]が出てきたことを記録している
    }

    cout << ans << endl;
    return 0;
}