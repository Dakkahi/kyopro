#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    ll s;
    cin >> s;
    priority_queue<ll, vector<ll>, greater<ll>> Q;
    for(ll i = 1; i <= s; i++){
        ll q;
        cin >> q;
        if(q == 1){
            ll x;
            cin >> x;
            Q.push(x);
        }
        if(q == 2) cout << Q.top() << endl;
        if(q == 3){
            Q.pop();
        }
    }
    return 0;
}