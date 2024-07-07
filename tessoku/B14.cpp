#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N+1);
    for(ll i = 1; i <= N; i++) cin >> A[i];

    ll former = N / 2;
    ll latter = N - former;

    vector<ll> P(1LL << former);
    vector<ll> Q(1LL << latter);

    for(ll i = 0; i < (1LL << former); i++) {
        P[i] = 0;
        for(ll j = 0; j < former; j++) {
            if((i & (1LL << j)) != 0LL) P[i] += A[j + 1];
        }
    }

    for(ll i = 0; i < (1LL << latter); i++) {
        Q[i] = 0;
        for(ll j = 0; j < latter; j++) {
            if((i & (1LL << j)) != 0LL) Q[i] += A[former + j + 1];
        }
    }

    sort(Q.begin(), Q.end());

    for(ll i = 0; i < (1LL << former); i++) {
        if(binary_search(Q.begin(), Q.end(), K - P[i])) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
