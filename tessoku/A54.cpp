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
    ll Q;
    cin >> Q;
    map<string, ll> M;
    for(ll i = 1; i <= Q; i++){
        ll q;
        cin >> q;
        if(q == 1){
            string x;
            ll y;
            cin >> x >> y;
            M[x] = y;
        }
        if(q == 2){
            string x;
            cin >> x;
            cout << M[x] << endl;
        }
    }
    return 0;
}