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

     ll sum = 0;

     for(ll i = 2; i <= N; i++){
        sum += A[i]*(i-1);
     }

     for(ll i = 1; i <= N-1; i++){
        sum -= (N-i)*A[i];
     }

     cout << sum << endl;
     return 0;
}