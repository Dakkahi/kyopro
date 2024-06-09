#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int main(){
    ll N, M;
    cin >> N >> M;

    ll H[N+1];
    for(ll i = 1; i <= N; i++) cin >> H[i];

    ll cnt = 0;
    for(ll i = 1; i <= N; i++){
        M -= H[i];
        if(M < 0) break;
        else cnt++;
    }

    cout << cnt << endl;
    return 0;

}