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
    ll a, b, c;
    cin >> a >> b >> c;

    ll val = 1;
    string ans = "No";

    for(ll i = 1; i <= b; i++){
        val *= c;
        if(val > a){
            ans = "Yes";
            break;
        } 
    }
    cout << ans << endl;
    return 0;
}