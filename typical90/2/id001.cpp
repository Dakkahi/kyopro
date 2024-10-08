#include <iostream>
using namespace std;

long long N, K, L;
long long A[1 << 18];

bool solve(long long M) {
    long long cnt = 0, pre = 0;
    for (int i = 1; i <= N; i++) {
        if (A[i] - pre >= M && L - A[i] >= M) {
            cnt += 1;
            pre = A[i];
        }
    }
    if (cnt >= K) return true;
    return false;
}

int main() {
    // Step #1. 入力
    cin >> N >> L;
    cin >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    // Step #2. 答えで二分探索（めぐる式二分探索法）
    long long left = -1;
    long long right = L + 1;
    while (right - left > 1) {
        long long mid = left + (right - left) / 2;
        if (solve(mid) == false) right = mid;
        else left = mid;
    }
    cout << left << endl;
    return 0;
}