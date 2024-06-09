#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 1; i <= (ll)(n); i++)
#define ll long long
#define bigmod 1000000007

ll modpow(ll p, ll exp, ll mod){//p^exp　(mod mod)を計算する。 左から順に(底,指数,mod)
  ll ans = 1;//出力
  while(exp != 0){
    if(exp%2 == 1){ans *= p; ans %= mod;}
    p = (p*p); p = p % mod;
    exp = exp/2;
  }
  return ans;
}

ll GCD(ll a,ll b){//最大公約数を求めるやつ
    if(b == 0) return a;
    return GCD(b,a%b);
}

ll LCM(ll a,ll b){//最小公倍数を求めるやつ
    return a*b/GCD(a,b);
}
 
ll division(ll a,ll b,ll m){//a÷b(mod m)を返す
    return (a*modpow(b,m-2,m)) % m;
}

 
int main() {
    ll a,b,c;
    cin >> a >> b >> c;
    ll ans = c;
    if(c == 1){
        cout << "No";
        return 0;
    }
    rep(i,b-1){
        if(a/ans < c){
            cout << "Yes";
            return 0;
        }
        ans *= c;
    }
    if(ans > a){
        cout << "Yes";
    }else{
        cout << "No";
    }
}