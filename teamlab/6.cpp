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
    //エラトステネスっぽい
    ll N = 1000000;
    bool visited[N+1];
    for(ll i = 2; i <= N; i++) visited[i] = false;

    stack<ll> Q;

    for(ll i = 2; i <= N; i++){
        for(ll j = i; j <= N; j += i){
            if(visited[j] == false){
                visited[j] = true;
                Q.push(j);
            }
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= 210001; i++){
        ans = Q.top();
        Q.pop();
    }
    cout << ans << endl;
    return 0;
}