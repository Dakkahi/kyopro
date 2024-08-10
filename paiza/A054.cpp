#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    ll N, M, Q;
    cin >> N >> M >> Q;
    pair<ll, ll> p[N+1];
    ll e[Q+1], t[Q+1];
    for(ll i = 1; i <= Q; i++) {
        cin >> e[i] >> t[i];
        p[i].first = e[i];
        p[i].second = t[i];
    }

    sort(p + 1, p + Q + 1);

    ll eff_max = 0;
    ll eff = 0;

    ll seq_start = 1;
    ll seq_start_stack = seq_start;
    
    ll q = 1;
    while(q <= Q){
        if(q == 1){
            for(ll m = 1; m <= M; m++){
                if(p[q+m].first - p[q+m-1].first == p[q+m].second - p[q+m-1].second){
                    eff += 1;
                }
            }
        }else{
            
        }
        q ++;
    }

}