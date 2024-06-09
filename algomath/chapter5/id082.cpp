#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    ll L[N+1], R[N+1];
    for(ll i = 1; i <= N; i++) cin >> L[i] >> R[i]; 

    vector<pair<ll, ll>> R_index;
    for(ll i = 1; i <= N; i++) {
        R_index.emplace_back(L[i], R[i]);
    }

    sort(R_index.begin(), R_index.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
        return a.second < b.second;
    });

    ll sum = 1; // 映画は必ず1本は見れるので
    ll end_time = R_index[0].second; // 最初の映画の終了時間を設定

    for(ll i = 1; i < N; i++) {
        if(end_time <= R_index[i].first) {
            end_time = R_index[i].second;
            sum++;
        }
    }
    cout << sum << endl;

    return 0;
}
