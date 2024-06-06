#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;

    ll A[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];

    //A[i]が最大になるのはA[i]を含んでかつA[i]以降が選ばれず，A[1]~A[i-1]が選ばれるか選ばれないかなので2^(i-1)通りである
    ll sum = 0;
    ll p = 1;

    ll mod = 1000000007;
    for(ll i = 1; i <= N; i++){
        ll a = A[i]%mod;
        sum += (a*p)%mod;
        p = (2*p)%mod;
    }
    cout << sum%mod << endl;
    return 0;
}