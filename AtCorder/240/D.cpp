#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long; 

vector<ll> G[200000+1];
bool visited[200000+1];
ll dist[200000+1];

ll cnt_total = 0;

void dfs(ll pos){
    visited[pos] = true;
    for(ll i : G[pos]){
        if(visited[i] == false){
            visited[i] = true;
            dfs(i);
        }
    }
}



int main(){
    ll N, K;
    cin >> N >> K;

    
    ll A[N], B[N];

    ll V[K+1];
    for(ll i = 1; i <= N-1; i++){
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    for(ll i  =1; i <= K; i++) cin >> V[i];

    


}