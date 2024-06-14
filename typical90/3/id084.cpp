#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;

    ll total = N * (N + 1) / 2;

    vector<ll> cnt;

    char sig = S[0];
    ll start = 0;
    for (ll i = 1; i < N; i++) {
        if (sig != S[i]) {
            cnt.push_back(i - start);
            start = i;
            sig = S[i];
        }
        if (i == N - 1) {
            if(start != 0){
            cnt.push_back(i - start + 1);
            }
        }
    }
    
    ll sum = 0;
    if(start == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (ll i = 0; i < cnt.size(); i++) {
        sum += cnt[i] * (cnt[i] + 1) / 2;
    }

    cout << total - sum << endl;
    return 0;
}
