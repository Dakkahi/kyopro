#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ll N;
    cin >> N;
    ll A[N], B[N];
    vector<ll> G[N+1];
    vector<ll> dist(N+1), ans(N+1);
    dist[1] = 0;
    ans[1] = -1;
    ans[0] = 0;
    for(ll i = 1; i <= N-1; i++){
         cin >> A[i]>> B[i];
         G[A[i]].push_back(B[i]);
         G[B[i]].push_back(A[i]);
         dist[i+1] = -1;
         ans[i+1] = -1;
    }

    queue<ll> Q;
    Q.push(1);
    while(!Q.empty()){
        ll pos = Q.front();
        Q.pop();
        for(ll i : G[pos]){
            if(dist[i] == -1){
                Q.push(i);
                dist[i] = dist[pos] + 1;
            }
        }
    }
    ll max_val = 0;
    ll index;
    for(ll i = 2; i <= N; i++){
        if(max_val <= dist[i]){
            index = i;
            max_val = dist[i];
        }
    }
    queue<ll> q;
    q.push(index);
    ans[index] = 0;
    while(!q.empty()){
        ll pos = q.front();
        q.pop();
        for(ll i : G[pos]){
            if(ans[i] == -1){
                q.push(i);
                ans[i] = ans[pos] + 1;
            }
        }
    }
    ll M = *max_element(ans.begin()+1, ans.end());
    cout << M + 1 << endl;
    return 0;
}