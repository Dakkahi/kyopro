#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;


int main(){
    ll N;
    cin >> N;

    map<ll, ll> M;
    ll A[N+1], W[N+1];
    //ll cnt = 0;
    ll sum = 0;
    ll ans = 0;

    for(ll i = 1; i <= N; i++) cin >> A[i];
    for(ll i = 1; i <= N; i++) cin >> W[i];

    for(ll i = 1; i <= N; i++){
        sum += W[i];
        if(M[A[i]] == 0) {
            M[A[i]] = W[i];
        }
        else{
            if(M[A[i]] < W[i]) M[A[i]] = W[i];
        }
    }

    for(const auto& pair : M){
        ans += pair.second;
    }
    cout << sum-ans << endl;
    
    return 0;
}