#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N+1);
    for(ll i = 1; i <= N; i++) cin >> A[i];

    ll sum = 0;
    for(ll i = 1; i <= N; i++) sum += A[i];

    // もし sum が 10 で割り切れないならば、部分和が存在しない
    if (sum % 10 != 0) {
        cout << "No" << endl;
        return 0;
    }

    ll val = sum / 10;
    ll current_sum = 0;
    ll start = 1;

    // 二重の範囲（循環）で見るため、2N-1 まで繰り返す
    for (ll end = 1; end <= 2 * N; end++) {
        current_sum += A[(end - 1) % N + 1];

        while (current_sum > val && start < end) {
            current_sum -= A[(start - 1) % N + 1];
            start++;
        }

        if (current_sum == val) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
