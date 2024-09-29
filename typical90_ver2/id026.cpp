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
pair<bool, char> visited[100001]; //(visited, color)

void dfs(ll pos, char color){
    visited[pos].first = true;
    if(color == 'r') visited[pos].second = 'b';
    else visited[pos].second = 'r';

    for(ll i:G[pos]){
        if(visited[i].first == false) dfs(i, visited[pos].second);
    }
}


int main(){
    ll N;
    cin >> N;
    for(ll i = 1; i <= N-1; i++){
        ll A, B;
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    for(ll i = 1; i <= N; i++){
        visited[i].first = false;
        if(i == 1) visited[i].second = 'r';
    }

    dfs(1, visited[1].second);

    ll cnt = 0;
    for(ll i = 1; i <= N; i++){
        if(visited[i].second == 'r') cnt++;
    }

    if(cnt >= N/2){
        ll c = 0;
        for(ll i = 1; i <= N; i++){
            if(visited[i].second == 'r'){
                c++;
                cout << i << " ";
            }
            if(c >= N/2) break;
        }
    }

    else{
        ll c = 0;
        for(ll i = 1; i <= N; i++){
            if(visited[i].second == 'b'){
                c++;
                cout << i << " ";
            }
            if(c >= N/2) break;
        }
    }

    return 0;
}