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
vector<ll> H[100001];
vector<ll> I;
ll cnts = 0;
bool visited[100001];

void dfs(ll pos){
    visited[pos] = true;
    for(ll i : G[pos]){
        if(!visited[i]) dfs(i);
    }
    I.push_back(pos);
}

void dfs2(ll pos){
    visited[pos] = true;
    cnts++;
    for(ll i : H[pos]){
        if(!visited[i]) dfs2(i);
    }
}

int main(){
    ll N, M;
    cin >> N >> M;
    ll A[M+1], B[M+1];
    for(ll i = 1; i <= M; i++) {
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        H[B[i]].push_back(A[i]);
    }
    for(ll i = 1; i <= N; i++) visited[i] = false;

    for(ll i = 1; i <= N; i++){
        if(!visited[i]) dfs(i);
    }

    ll ans = 0;
    reverse(I.begin(), I.end());
    for(ll i = 1; i <= N; i++) visited[i] = false;
    for(ll i : I){
        if(visited[i]) continue;
        cnts = 0;
        dfs2(i);
        ans += cnts*(cnts-1)/2;
    }
    cout << ans << endl;
	return 0;

}