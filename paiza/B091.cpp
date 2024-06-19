#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

int main(){
     ll N;
     cin >> N;
     ll h[(N+2)*(N+2)+1];
     for(ll i = 1; i <= (N+2)*(N+2); i++) h[i] = 0;

    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= N; j++) cin >> h[i*(N+2) + j+1];
    }
    vector<ll> G;
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= N; j++){
            if(h[(i-1)*(N+2) + j+1] < h[i*(N+2) + j+1] && h[(i+1)*(N+2) + j+1] < h[i*(N+2) + j+1] && h[i*(N+2) + j] < h[i*(N+2) + j+1] && h[i*(N+2) + j+2] < h[i*(N+2) + j+1]){
                G.push_back(h[i*(N+2) + j+1]);
            }
        }
    }
    sort(G.rbegin(), G.rend());
    for(ll i = 0; i < G.size(); i++){
        cout << G[i] << endl;
    }
    return 0;
}