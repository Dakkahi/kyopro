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

//LIS

class SegTree{
    public:
    ll dat[600001];
    ll siz = 1;
    void init(ll N){
        while(siz < N) siz *= 2;
        for(ll i = 1; i < 2*siz; i++) dat[i] = 0;
    }

    void update(ll pos, ll x){
        dat[pos] = x;
        while(pos > 1){
            pos /= 2;
            dat[pos] = max(dat[2*pos], dat[2*pos+1]);
        }
    }

    ll query(ll l, ll r, ll a, ll b, ll u){ //[l, r)の中の最大値を求める
        if(r <= a || b <= l) return -1000000;
        if(l <= a && b <= r) return dat[u];
        ll m = (a+b)/2;
        ll ansL = query(l, r, a, m, 2*u);
        ll ansR = query(l, r, m, b, 2*u+1);
        return max(ansL, ansR);
    }
};

int main(){
    ll N;
    cin >> N;
    ll A[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];
    ll dp[N+1];
    ll L[N+1];
    ll len;

    for(ll i = 1; i <= N; i++){
        if(i == 1){
            dp[i] = 1;
            L[i] = A[i];
            len = 1;
        }else{
            ll pos = lower_bound(L+1, L+len+1, A[i]) - L;
            dp[i] = pos;
            L[dp[i]] = A[i];
            if(dp[i] > len) len ++;
        }
    }

    ll rev_dp[N+1];
    ll rev_L[N+1];
    ll rev_len;

    for(ll j = N; j >= 1; j--){
        if(j == N){
            rev_dp[j] = 1;
            L[1] = A[j];
            rev_len = 1;
        }else{
            ll pos = lower_bound(L+1, L+rev_len+1, A[j]) - L;
            rev_dp[j] = pos;
            L[rev_dp[j]] = A[j];
            if(rev_dp[j] > rev_len) rev_len ++;
        }
    }
    ll M = 0;
    for(ll i = 1; i <= N; i++){
        M = max(M, dp[i]+rev_dp[i]-1);
        //cout << rev_dp[i] << endl;
    }

    cout << M << endl;
    return 0;
}