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
    vector<pair<ll, ll> > G[N+1]; //(to, len)

    ll A[M+1], B[M+1], C[M+1];
    for(ll i = 1; i <= M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        G[A[i]].push_back(make_pair(B[i], C[i]));
        G[B[i]].push_back(make_pair(A[i], C[i]));
    }
    priority_queue<pair<ll, ll> , vector<pair<ll, ll> >, greater<pair<ll, ll> > > Q; //(dist, idx)

    bool decided[N+1];
    ll dist_from1[N+1];
    ll dist_fromN[N+1];
    for(ll i = 1; i <= N; i++){
        decided[i] = false;
        dist_from1[i] = M*10000;
        dist_fromN[i] = M*10000;
    }

    Q.push(make_pair(0, 1));

    dist_from1[1] = 0;

    while(!Q.empty()){
        ll pos = Q.top().second;
        Q.pop();

        if(decided[pos] == true) continue;

        decided[pos] = true;
        for(ll i = 0; i < G[pos].size(); i++){
            ll nexpos = G[pos][i].first;
            ll nexdist = G[pos][i].second;

            if(decided[nexpos] == false){
                if(dist_from1[nexpos] > dist_from1[pos] + nexdist){
                    dist_from1[nexpos] = dist_from1[pos] + nexdist;
                    Q.push(make_pair(dist_from1[nexpos], nexpos));
                }
            }
        }
    }

    Q.push(make_pair(0, N));
    dist_fromN[N] = 0;

    for(ll i = 1; i <= N; i++) decided[i] = false;

    while(!Q.empty()){
        ll pos = Q.top().second;
        Q.pop();

        if(decided[pos] == true) continue;

        decided[pos] = true;
        for(ll i = 0; i < G[pos].size(); i++){
            ll nexpos = G[pos][i].first;
            ll nexdist = G[pos][i].second;

            if(decided[nexpos] == false){
                if(dist_fromN[nexpos] > dist_fromN[pos] + nexdist){
                    dist_fromN[nexpos] = dist_fromN[pos] + nexdist;
                    Q.push(make_pair(dist_fromN[nexpos], nexpos));
                }
            }
        }
    }

    for(ll i = 1; i <= N; i++){
        cout << dist_from1[i] + dist_fromN[i] << endl;
    }

    return 0;
}