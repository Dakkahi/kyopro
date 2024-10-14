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
using ll = unsigned long long;

int main(){
    ll K;
    cin >> K;
    vector<ll> v;
    ll cnt = 0; //1*1*K
    for(ll i = 1; i*i <= K; i++){
        if(K%i == 0){
            v.push_back(i);
            if(i*i != K) v.push_back(K/i);
        }
    }

    sort(v.begin(), v.end());
    for(ll i = 0u; i < v.size(); i++){
        ll a = v[i];
        //cout << v[i] << endl;
        for(ll j = i; j < v.size(); j++){
            ll b = v[j];
            if ((K / a) < b) continue;
            if(K%(a*b) == 0LL && K/(a*b) >= b) cnt++;
            //else cout << b << " " << K/(a*b) << endl;
        }
    }
    cout << cnt << endl;
    return 0;
}