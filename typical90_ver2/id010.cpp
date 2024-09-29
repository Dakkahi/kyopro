#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    ll C[N+1], P[N+1];
    ll sum[3][N+1]; //sum[i][j]で学籍番号jまでのi組の点数の合計
    sum[1][0] = 0;
    sum[2][0] = 0;
    for(ll i = 1; i <= N; i++) {
        cin >> C[i] >> P[i];
        sum[C[i]][i] = sum[C[i]][i-1] + P[i];
        sum[3-C[i]][i] = sum[3-C[i]][i-1];
    }

    ll Q;
    cin >> Q;
    for(ll i = 1; i <= Q; i++){
        ll L, R;
        cin >> L >> R;
        ll A = sum[1][R] - sum[1][L-1];
        ll B = sum[2][R] - sum[2][L-1];
        cout << A << " " << B << endl;
    }
    return 0;
}