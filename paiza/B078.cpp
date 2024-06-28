#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;


int main(){
    ll N;
    cin >> N;
    vector<pair<ll, ll>> mov; //mov[0]に開始時間、mov[1]に終了時間
    for(ll i = 0; i < N; i++){
        ll s, p;
        cin >> s >> p;
        s *= 2;
        p *= 2;
        ll f = s+p;
        mov.push_back(make_pair(s - 1, f));
    } //時間を全部2倍にしてスタートから1引けば何も考えずに貪欲法ができる
    sort(mov.begin(), mov.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return a.second < b.second;
    });

    ll cnt = 1;
    ll t = mov[0].second;
    
    for(ll i = 1; i < N; i++){
        if(t < mov[i].first){ //開始時間が終了時間より後であれば
            t = mov[i].second;
            cnt ++;
        }
    }
    cout << cnt << endl;
    return 0;
}