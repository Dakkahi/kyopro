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
    ll A[N+1], B[N+1];
    for(ll i = 1; i <= N;i++) cin >> A[i];
    for(ll i = 1; i <= N; i++) cin >> B[i];

    sort(A+1, A+N+1);
    sort(B+1, B+N+1);

    ll ans = 0;
    for(ll i = 1; i <= N; i++){
        ans += abs(A[i]-B[i]);
    }

    cout << ans << endl;
    return 0;
    }