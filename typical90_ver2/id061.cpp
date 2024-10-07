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
    ll Q;
    cin >> Q;

    deque<ll> q;
    for(ll i = 1; i <= Q; i++){
        ll t, x;
        cin >> t >> x;
        if(t == 1) q.push_front(x);
        if(t == 2) q.push_back(x);
        if(t == 3) cout << q[x-1] << endl;
    }
    return 0;
}