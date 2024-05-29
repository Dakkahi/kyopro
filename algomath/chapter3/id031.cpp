#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int N, A[100009], dp[100009];

int main(){
    cin >> N;
    for(int i = 1; i<= N; i++) cin >> A[i];
    for(int i = 0; i <= N; i++){
        if(i == 0) dp[i] = 0;
        if(i == 1) dp[i] = A[i];
        if(i >= 2){
            int v1 = dp[i-1];
            int v2 = dp[i-2] + A[i];
            dp[i] = max(v1, v2);
        }
    }
    cout << dp[N] << endl;
    return 0;
}