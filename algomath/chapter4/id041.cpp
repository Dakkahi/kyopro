#include<iostream>
#include<cmath>
using namespace std;

int main(){
    long long T, N;

    cin >> T;
    cin >> N;

    long long L[N+4], R[N+4];

    long long sum[500005] = {0};
    long long ans[500005] = {0};


    for(int i = 1; i <= N; i++) cin >> L[i] >> R[i];


//t+0.5時間後の人数はsum[t+1]に格納．最後に逆向きに足していけば累積和となる
    for(int j = 1; j <= N ; j++){
        sum[R[j]] += 1;
        sum[L[j]] -= 1; 
    }
    ans[T] = sum[T];
    for(int k = T-1; k >= 1 ; k--){
        ans[k] = sum[k] + ans[k+1]; 
    }

    for(int r = 1; r <= T; r++){
        cout << ans[r] << endl;
    }
    return 0;
}