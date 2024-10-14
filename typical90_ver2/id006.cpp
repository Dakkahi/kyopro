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
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    ll c[N+1][26+1];
    for(ll i = 0; i < 26; i++) c[N][i] = N;

    for(ll i = N-1; i >= 0; i--){
        for(ll j = 0; j < 26; j++){
            if((ll)(S[i] - 'a') == j) c[i][j] = i;
            else c[i][j] = c[i+1][j];
        }
    }

    string ans = "";
    ll currentpos = 0;

    for(ll i = 1; i <= K; i++){
        for(ll j = 0; j < 26; j++){
            ll nexpos = c[currentpos][j];
            ll maxpossiblelength = (ll)(N - nexpos - 1) + i;
            if(maxpossiblelength >= K){
                ans += (char)('a' +  j);
                currentpos = nexpos + 1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}