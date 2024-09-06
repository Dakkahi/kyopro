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
    ll N, M;
    cin >> N >> M;
    vector<ll> G[N+1];
    for(ll i = 1; i <= M; i++){
        ll A, B;
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    priority_queue<pair<ll, ll> > Q;

    for(ll i = 1; i <= N; i++) Q.push(make_pair(G[i].size(), i));

    pair<ll, ll> head = Q.top();
    cout << head.second << endl;
    return 0;
    
}