#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<ll> R;
vector<ll> L;

// T以下の要素がいくつあるかを返す関数
ll count_less_than_equal_to(const vector<ll>& vec, ll T) {
    return upper_bound(vec.begin(), vec.end(), T) - vec.begin();
}

int main() {
    ll N, T;
    cin >> N >> T;
    string S;
    cin >> S;
    vector<ll> X(N);
    for (ll i = 0; i < N; i++) cin >> X[i];

    for (ll i = 0; i < N; i++) {
        if (S[i] == '1') R.push_back(X[i]);
        else L.push_back(X[i]);
    }

    sort(R.begin(), R.end());
    sort(L.begin(), L.end());
    ll sum = 0;

    for (ll i = 0; i < R.size(); i++) {
        ll count_T_plus_Ri = count_less_than_equal_to(L, 2*T + R[i]);
        ll count_Ri = count_less_than_equal_to(L, R[i]);
        sum += count_T_plus_Ri;
        sum -= count_Ri;
    }

    cout << sum << endl;
    //for(ll i = 0; i < L.size(); i++) cout << L[i] << endl;
    return 0;
}
