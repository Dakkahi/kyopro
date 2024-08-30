#include <iostream>
#include <string>
#include <map>
#include<set>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    set<ll> S;
    ll Q;
    cin >> Q;

    for(ll i = 1; i <= Q; i++){
        ll q, x;
        cin >> q >> x;
        if(q == 1){
            S.insert(x);
        }
        if(q == 2){
            S.erase(x);
        }
        if(q == 3){
            auto itr = S.lower_bound(x);
            if(itr == S.end()){
                cout << -1 << endl;
            }else{
                cout << *itr << endl;
            }
        }
    }
    return 0;
}