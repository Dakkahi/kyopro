#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    ll N, M;
    cin >> N >> M;
    string s[N+1], w[M+1];
    for(ll i = 1; i <= N; i++) cin >> s[i]; //0インデックスなのに注意
    for(ll i = 1; i <= M; i++) cin >> w[i];

    queue<pair<ll, ll>> Q;

    for(ll i = 1; i <= M; i++){
        for(ll j = 1; j <= N; j++){
            for(ll k = 0; k < N; k++){
                if(w[i][0] == s[j][k]){
                    bool flag = true;
                    for(ll r = 1; r < w[i].length(); r++){
                        if(r + j > N || r + k+1 > N){
                            flag = false;
                            break;
                        }
                        else if(w[i][r] != s[j+r][k+r]){
                            flag = false;
                            break;
                        }
                    }
                    if(flag == true) Q.push(make_pair(k+1,j));
                }
            }
        }
    }
    while(!Q.empty()){
        ll i = Q.front().first;
        ll j = Q.front().second;
        Q.pop();
        cout << i << " " << j << endl;
    }
    return 0;
}