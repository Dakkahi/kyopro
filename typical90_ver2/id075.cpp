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

    ll cnt = 0;

    for(ll i = 2; i*i <= N; i++){
        if(N%i == 0){
            while(N%i == 0){
                N /= i;
                cnt++;
            }
        }
    }

    if(N > 1) cnt ++;
    ll ans = 0;
    ll siz = 1;
    while(cnt > siz){
        siz *= 2;
        ans ++;
    }

    cout << ans << endl;
    //cout << cnt << endl;
    return 0;
    
}