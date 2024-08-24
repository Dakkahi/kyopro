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
    ll N, L; 
    cin >> N >> L;
    pair<ll, char> person[N+1];
    for(ll i = 1; i <= N; i++) cin >> person[i].first >> person[i].second;

    ll ans = 0;
    for(ll i = 1; i <= N; i++){
        if(person[i].second == 'E') ans = max(ans, L-person[i].first);
        if(person[i].second == 'W') ans = max(ans, person[i].first);
    }
    cout << ans << endl;
    return 0;

}