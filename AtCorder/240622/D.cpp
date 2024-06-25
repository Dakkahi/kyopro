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

ll div_mod(ll a){
    return a%mod;
}

ll mod_pow(ll a, ll n){
    ll ans = 1;
    ll p = a;
    for(ll i = 0; i < 60; i++){
        if((n & 1LL << i) != 0LL){
            ans = div_mod(ans*p);
        }
        p = div_mod(p*a);
    }
    return ans%mod;
}



int main(){
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    ll q = 0;
    for(ll i = 0; i < N; i++){
        if(S[i] == '?') q++;
    }


    ll cnt = 0;
    for(ll i = 0; i < N-K+1; i++){
        if(S[i] == S[i+K] || S[i] == '?' || S[i+K] == '?'){
            if(K == 2) cnt ++;
            else{
                bool flag = true;
                for(ll j = 1; j < K/2; j++){
                    if(S[i+j] != S[i+K-j] && S[i+j] != '?' && S[i+K-j] != '?'){
                        flag = false;
                        break;
                    }
                }
                if(flag == true) cnt++;
            }
        }
    }
    ll ans = (mod_pow(2, q) + mod - cnt)%mod;

    cout << ans << endl;
    return 0;


}