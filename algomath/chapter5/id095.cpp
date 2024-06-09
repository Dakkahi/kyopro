#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    vector<ll> C(N+1), P(N+1);
    for(ll i = 1; i <= N; i++) cin >> C[i] >> P[i];

    ll Q;
    cin >> Q;
    vector<ll> L(Q+1), R(Q+1);
    for(ll i = 1; i <= Q; i++) cin >> L[i] >> R[i];

    // クラス1とクラス2の累積和
    vector<ll> sum_1(N+1, 0), sum_2(N+1, 0);
    for(ll i = 1; i <= N; i++){
        sum_1[i] = sum_1[i-1] + (C[i] == 1 ? P[i] : 0);
        sum_2[i] = sum_2[i-1] + (C[i] == 2 ? P[i] : 0);
    }

    // 各クエリに対して累積和を使って範囲の合計得点を求める
    for(ll i = 1; i <= Q; i++){
        ll start = L[i];
        ll goal = R[i];
        ll total_1 = sum_1[goal] - sum_1[start-1];
        ll total_2 = sum_2[goal] - sum_2[start-1];
        cout << total_1 << " " << total_2 << endl;
    }

    return 0;
}
