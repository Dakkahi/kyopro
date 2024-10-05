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

vector<ll> G[100000+1];
ll dp[100000+1];

void dfs(ll pos, ll pre){
    dp[pos] = 1;
    for(ll i : G[pos]){
        if(i != pre){
            dfs(i, pos);
            dp[pos] += dp[i];
        }
    }
}

int main(){
    ll N;
    cin >> N;
    ll a[N], b[N];
    for(ll i = 1; i <= N-1; i++) {
        cin >> a[i] >> b[i];
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }

    dfs(1, 0);

    ll sum = 0;
    for(ll i = 1; i <= N; i++){
        sum += dp[i]*(N-dp[i]);
    }
    cout << sum << endl;
    return 0; 
}