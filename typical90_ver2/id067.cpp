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

ll eight_to_nine(ll n){
    ll p = 1;
    ll val = 0;
    for(ll i = 1; i <= 20; i++){
        val += (n%10)*p;
        p *= 8;
        n /= 10;
    }//ここまでで10進法に変換
    ll ans = 0;
    ll q = 1;
    while(val > 0){
        ans += (val%9)*q;
        q *= 10;
        val /= 9;
    }
    //cout << ans << endl;
    string s = to_string(ans);
    for(ll i = 0; i < s.size(); i++){
        if(s[i] == '8') s[i] = '5';
    }
    ll a = stoll(s);
    return a;
}


int main(){
    ll N, K;
    cin >> N >> K;

    for(ll i = 1; i <= K; i++) N = eight_to_nine(N);
    cout << N << endl;
    return 0;
}