#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    ll A[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i];

    ll dp[N+1]; //N日目に挙げられる実力の最大値
    dp[0] = 0;
    dp[1] = A[1];

    for(ll i = 2; i <= N; i++) dp[i] = max(dp[i-1], dp[i-2] + A[i]);

    cout << dp[N] << endl;
    return 0;
    


}