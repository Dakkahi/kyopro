#include <iostream>

using namespace std;

long long N;
long long p10[19], R[19][10];

int main() {
    p10[0] = 1;
    for (int i = 1; i < 19; i++) p10[i] = 10LL * p10[i - 1];
    cin >> N;
    for (int i = 0; i < 15; i++) {
        long long dig = (N / p10[i]) % 10LL;
        for (int j = 0; j < 10; j++) {
            if (j < dig) R[i][j] = N / p10[i + 1] * p10[i] + p10[i];
            if (j == dig) R[i][j] = N / p10[i + 1] * p10[i] + (N % p10[i]) + 1LL;
            if (j > dig) R[i][j] = N / p10[i + 1] * p10[i];
        }
    }
    long long ans = 0;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++) ans += 1LL * j * R[i][j];
    }
    cout << ans << endl;
    return 0;
}
