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

int main(){
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    ll mod = 2147483647;

    ll hash[N+1];
    ll pow[N+1];
    ll p = 1;
    hash[0] = 0;

    for(ll i = 0; i < N; i++){
        ll x = S[i];
        if(i == 0){
            pow[i+1] = 100;
            hash[i+1] = x;
            hash[i+1]%= mod; 
        }else{
            pow[i+1] = (100*pow[i])%mod;
            //ll x = S[i];
            hash[i+1] = hash[i]*100 + x;
            hash [i+1] %= mod;
        }
        //cout << x << endl;
    }

    for(ll i = 1; i <= Q; i++){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll hash_ab = hash[b] - (hash[a-1]*pow[b-a+1])%mod;
        if(hash_ab < 0) hash_ab += mod;
        ll hash_cd = hash[d] - (hash[c-1]*pow[d-c+1])%mod;
        if(hash_cd < 0) hash_cd += mod;

        if(hash_ab == hash_cd) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}