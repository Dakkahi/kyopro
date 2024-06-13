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
    ll a, b, c;
    cin >> a >> b >> c;

    ll d = 1;
    for(ll i = 0; i <= 60; i++){
        if((b & (1LL << i)) != 0){
            d *= c;
        }
        c *= c;
    }
    if(a < d) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}