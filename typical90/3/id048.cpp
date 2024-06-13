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
    ll N, K;
    cin >> N >> K;
    ll A[N+1], B[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i] >> B[i];
    vector<bool> flag(N+1, false);

    ll C[2*N+1];
    for(ll i = 1; i <= N; i++) C[i] = A[i] - B[i];
    for(ll i = N+1; i <= 2*N; i++) C[i] = B[i-N];

    sort(C+1, C+2*N+1, greater<ll>());

    ll ans = 0;
    for(ll i = 1; i <= K; i++){
        ans += C[i];
    }
    cout << ans << endl;
    return 0;
}