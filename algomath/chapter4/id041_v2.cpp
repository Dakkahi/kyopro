#include<iostream>
#include<cmath>
using namespace std;

int main(){
    long long T, N;

    cin >> T;
    cin >> N;

    long long L[N+1], R[N+1];
    for(long long i = 1; i <= N; i++) cin >> L[i] >> R[i];

    long long sum[T+1];
    long long dif[T+1];

    for(long long j = 0; j < T; j++){
        sum[j] = 0;
        dif[j] = 0;
    }

    for(long long i = 1; i <= N; i++){
        dif[L[i]] += 1;
        dif[R[i]] -= 1;
    }

    for(long long j = 0; j < T; j++){
        if(j == 0) sum[j] = dif[j];
        else{
            sum[j] = dif[j] + sum[j-1];
        }
        cout << sum[j] << endl;
    }
    return 0;
}