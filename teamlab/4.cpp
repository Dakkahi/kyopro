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
    string moji = "AEKLNORST";
    string c = "OK";

    ll all = 9*9*9*9*9;

    string S[all+1];
    ll cnt = 0;

    for(ll i = 0; i < all; i++){
        ll stack = i;
        S[i] = "AAAAA";
        for(ll j = 0; j < 5; j++){
            ll num = stack%9;
            S[i][j] = moji[num];
            stack = stack/9;
        }

        for(ll j = 0; j < 4; j++){
            if(S[i][j] == 'O' && S[i][j+1] == 'K'){
                cnt ++;
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}