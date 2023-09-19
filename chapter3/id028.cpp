#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;


int N, H[100009], dp[100009]; 

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> H[i];

    for(int i = 1; i <= N; i++){
        if(i == 1) dp[i] = 0;
        if(i == 2) dp[i] = abs(H[i] - H[i-1]);
        if(i >= 3){
            int v1 = dp[i-1] + abs(H[i] - H[i-1]);
            int v2 = dp[i-2] + abs(H[i] - H[i-2]);
            dp[i] = min(v1, v2);
        }
    }
    cout << dp[N] << endl;
    return 0;
}
