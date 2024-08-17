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
    ll N;
    cin >> N;
    ll L[N+1], R[N+1];
    pair<ll, ll> time[N+1];
    for(ll i = 1; i <= N; i++) {
        cin >> L[i] >> R[i];
        //最初の要素を開始時刻，二つ目の要素を終了時刻
        time[i].second = L[i];
        time[i].first = R[i];
    }

    sort(time+1, time+N+1);

    ll cnt = 0;
    ll end_time = 0;
    for(ll i = 1; i <= N; i++){
        if(end_time <= time[i].second){
            cnt ++;
            end_time = time[i].first;
        }
    }
    cout << cnt << endl;
    return 0;
}