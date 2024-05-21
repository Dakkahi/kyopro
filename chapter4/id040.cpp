#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int N;
    int M;
    long long ans = 0;

    cin >> N;
    long long A[N+2];
    long long sum[N+2];
    sum[0] = 0;
    sum[1] = 0;
    for(int i = 1; i <= N-1; i++) {
        cin >> A[i];
        sum[i+1] = sum[i] + A[i];

    }
    cin >> M;
    int B[M+2];
    for(int i = 1; i <= M; i++) cin >> B[i];


    for(int r = 1; r <= M-1; r++){
        ans += abs(sum[B[r+1]] - sum[B[r]]);
    }
    cout << ans << endl;

    return 0;
}