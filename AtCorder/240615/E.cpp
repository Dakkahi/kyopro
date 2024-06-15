#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

ll mod = 998244353;

ll div(ll a){
    return a%mod;
}

ll mod_pow(ll a, ll b){ //a^bをmodで割ったあまり
    ll ans = 1;
    ll p = a;
    for(ll i = 0; i <= 60; i++){
        if((b & (1LL << i)) != 0LL){
            ans = div(ans)*div(p);
        }
        p = div(p)*div(a);
    }
    return div(ans);
}

ll kaijo(ll N){
    ll ans = 1;
    for(ll i = 1; i <= N; i++){
        ans = div(ans)*div(ans);
    }
    return div(ans);
}

ll ncr_mod(ll n, ll r){
    if(r == 0 || r == n) return 1;
    else{
    ll ans = div(kaijo(n)*mod_pow(kaijo(r), mod-2))*mod_pow(kaijo(n-r), mod-2);
    return div(ans);
    }
}

 int main(){
    ll K;
    cin >> K;
    ll C[27];
    for(ll i  =1; i <= 26; i++) cin >> C[i];

    //まずは不可能判定
    ll tmp = 0;
    for(ll i = 1; i <= 26; i++) tmp += C[i];
    if(tmp < K){
        cout << 0 << endl;
        return 0;
    }
    else{
        sort(C+1, C+27);
        ll dp[K+1][27]; //dp[i][j]で長さiの文字列で文字jまで使う時の場合の数

        ll sum = 0;
        for(ll i = 1; i <= K; i++){
            for(ll j = 1; j <= 26; j++){
                dp[i][j] = 0;
                if(i == 1){
                    if(C[j] != 0){
                        if(j == 1) dp[i][j] = 1;
                        else dp[i][j] = dp[i][j-1] + 1;
                    }
                }
                else{
                    for(ll k = 0; k <= min(C[j], i); k++){
                        dp[i][j] += div(div(dp[i][j])*ncr_mod(i,k));
                    }
                }
            }
        }
        cout << div(dp[K][26]) << endl;
    }
    


 }