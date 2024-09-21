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

vector<ll> G[100001];
bool visited[100001];
ll ans[100001];

ll dfs(ll pos){
    visited[pos] = true;
    for(ll i : G[pos]){
        if(visited[i] == true) continue;
        ans[pos] = ans[pos] + dfs(i) + 1;
    }
    return ans[pos];
}

int main(){
    ll N;
    cin >> N;
    ll A[N+1];
    for(ll i = 2; i <= N; i++){
        cin >> A[i];
        G[A[i]].push_back(i);
        ans[i] = 0;
        visited[i] = false;
    }

    ll dummy = dfs(1);

    for(ll i = 1; i <= N; i++) cout << ans[i] << " ";
    return 0;
}