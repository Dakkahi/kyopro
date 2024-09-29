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
    ll mod = 181;
    string ans = "";
    for(ll i = 1; mod*i + 18 <= 88888888; i++){
        ll num = mod*i + 18;
        string S = to_string(num);
        bool flag = true;
        for(ll j = 0; j < S.size(); j++){
            if(!(S[j] == '1' || S[j] == '8')){
                flag = false;
                break;
            }
        }
        if(flag == true) ans = S;
    }
    cout << ans << endl;
    return 0;
}