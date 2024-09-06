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

    for(ll i = 1; i <= N; i++){
        cout << i << ": {";
        for(ll j = 0; j < G[i].size(); j++){
            if(j == 0) cout << G[i][j];
            else cout << ", " << G[i][j];
        }
        cout << '}' << endl;
    }
    return 0;
}