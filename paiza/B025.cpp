#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;


int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    ll r[M+1];
    ll H[N+1];
    queue<ll> Q; //各うさぎの位置を保存するキュー
    for(ll i = 1; i <= N; i++) H[i] = 0;
    for(ll i = 1; i <= M; i++) {
        cin >> r[i];
        H[r[i]] = i;
        Q.push(r[i]);
    }

    
    for(ll a = 1; a <= K; a++){
        for(ll c = 1; c <= M; c++){
            ll pos = Q.front();
            Q.pop();
            H[pos] = 0;
            pos ++;
            pos = (pos-1)%N+1;
            while(H[pos] != 0){
                pos++;
                pos = (pos-1)%N+1;
            }
            Q.push(pos);
            H[pos] = c;
        }
    }
    while(!Q.empty()){
        cout << Q.front() << endl;
        Q.pop();
    }
    return 0;
}