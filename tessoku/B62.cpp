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
stack<ll> S;

bool found = false;

void dfs(ll pos, ll N){
    if(found) return;  // 経路が見つかったら探索を終了
    visited[pos] = true;
    S.push(pos);  // 現在の位置をスタックに追加
    
    if(pos == N){  // 目的の頂点に到達したらフラグをセットして終了
        found = true;
        return;
    }

    for(ll i : G[pos]){
        if(!visited[i]){
            dfs(i, N);  // 再帰的にDFS
            if(found) return;  // 目的の頂点が見つかっていたら終了
        }
    }

    if(!found) S.pop();  // 目的地にたどり着けなかった場合、スタックから取り除く
}


int main(){
    ll N, M;
    cin >> N >> M;
    ll A, B;
    for(ll i = 1; i <= M; i++){
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    dfs(1, N);

    stack<ll> ans;

    while(!S.empty()){
        ll head = S.top();
        S.pop();
        ans.push(head);
    }

    while(!ans.empty()){
        ll f = ans.top();
        ans.pop();
        cout << f << " ";
    }
    return 0;
}