#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    ll N, M;
    cin >> N >> M;
    ll max = 120;
    vector<ll> G[N+1];
    ll A[M+1], B[M+1];
    ll dist[N+1]; //人1との年齢差
    bool flag[N+1];
    for(ll i = 1; i <= M; i++){
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    for(ll i = 1; i <= N;i++){
        dist[i] = 0;
        flag[i] = false;
    }

    queue<ll> Q;
    Q.push(1);
    flag[1] = true;
    while(!Q.empty()){
        ll head = Q.front();
        Q.pop();
        for(ll i : G[head]){
            if(flag[i] == false){
                flag[i] = true;
                dist[i] = dist[head] + 1;
                Q.push(i);
            }
        }
    }
    for(ll i = 1; i <= N; i++) {
        if(flag[i] == false) cout << 120 << endl;
        else{
            if(dist[i] > 120) cout << 120 << endl;
            else cout << dist[i] << endl;
        }
    }
    return 0;
}