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

void dfs(ll pos){
    visited[pos] = true;
    for(ll i : G[pos]){
        if(visited[i] == false) dfs(i);
    }
}

int main(){
    ll N, M;
    cin >> N >> M;
    ll A, B;
    for(ll i = 1; i<= M; i++){
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    for(ll i = 1; i<= N; i++) visited[i] = false;
    dfs(1);

    bool ans = true;
    for(ll i = 1; i <= N; i++){
        if(visited[i] == false){
            ans = false;
            break;
        }
    }
    if(ans == true) cout << "The graph is connected." << endl;
    else cout << "The graph is not connected." << endl;
}