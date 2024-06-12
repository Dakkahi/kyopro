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
    ll Q;
    cin >> Q;
    ll t[Q+1], x[Q+1];
    for(ll i = 1; i <= Q; i++) cin >> t[i] >> x[i];

    deque<ll> q;
    for(ll i = 1; i <= Q; i++){
        if(t[i] == 1) q.push_front(x[i]);
        else if(t[i] == 2) q.push_back(x[i]);
        else{
            cout << q[x[i]-1] << endl;
        }
    }
    return 0;

}