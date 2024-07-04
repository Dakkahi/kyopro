#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;

    vector<ll> A(N);
    for(ll i = 0; i < N; i++) cin >> A[i];

    ll count = 0;
    ll sum = 0;
    ll right = 0;

    for(ll left = 0; left < N; left++) {
        // 右端を可能な限り右に伸ばす
        while(right < N && sum + A[right] <= K) {
            sum += A[right];
            right++;
        }
        // ここで、sum + A[right] > K となるので、right を含まない部分列 [left, right) は条件を満たす
        count += (right - left);

        // 左端を1つ右にずらす
        sum -= A[left];
    }

    cout << count << endl;

    return 0;
}
