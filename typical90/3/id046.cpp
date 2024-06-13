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
    ll A[N+1], B[N+1], C[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];
    for(ll i = 1; i <= N; i++) cin >> B[i];
    for(ll i = 1; i <= N; i++) cin >> C[i];
     

    vector<ll> a[46];
    vector<ll> b[46];
    vector<ll> c[46];
    ll mod = 46;
    

    for(ll i = 1; i <= N; i++){
        a[A[i]%mod].push_back(A[i]);
        b[B[i]%mod].push_back(B[i]);
        c[C[i]%mod].push_back(C[i]);
    }

    ll cnt = 0;

    for(ll i = 0; i < mod; i++){
        for(ll j = 0; j < mod;j++){
            for(ll k = 0; k < mod; k++){
                if((i+j+k)%mod == 0){
                    cnt += (a[i].size())*(b[j].size())*(c[k].size());
                }
            }
        }
    }

    cout << cnt << endl;
    return 0;
}