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
    ll N;
    cin >> N;
    ll A, B, C;
    cin >> A >> B >> C;

    ll L = 9999;

    ll ans = L;

    for(ll i = 0; i <= L; i++){
        for(ll j = 0; i+j <= L; j++){
            ll money = N;
            money = money - i*A - j*B;
            if(money < 0) continue;
            
            if(money%C == 0) ans = min(ans, i+j+money/C);
        }
    }
    cout << ans << endl;
    return 0;
}