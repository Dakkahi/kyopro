#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int N, dp[109];

int main(){
    cin >> N;
    for(int i = 0; i <= N; i++){
        if(i <= 1) dp[i] = 1;
        if(i >= 2) dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[N] << endl;
    return 0;
}