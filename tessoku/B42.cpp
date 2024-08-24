#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    ll A[N+1], B[N+1];
    for(ll i = 1; i <= N; i++) cin >> A[i] >> B[i];

    //表と裏で正負のどちらを採用するか4通り考えれば良い

    ll max_val = 0;
    ll val = 0;
    //表表
    for(ll i = 1; i <= N; i++){
        if(A[i] >= 0 && B[i] >= 0) val += (A[i]+B[i]);
        if(A[i] < 0 && B[i] > 0 && B[i]+A[i] > 0) val += (A[i] + B[i]); 
        if(A[i] > 0 && B[i] < 0 && B[i]+A[i] > 0) val += (A[i] + B[i]); 
    }
    max_val = max(max_val, val);

    val = 0;
    //表裏
    for(ll i = 1; i <= N; i++){
        if(A[i] >= 0 && B[i] <= 0) val += (A[i] - B[i]);
        if(A[i] < 0 && B[i] < 0 && A[i] - B[i] > 0) val += (A[i] - B[i]); 
        if(A[i] > 0 && B[i] > 0 && A[i] - B[i] > 0) val += (A[i] - B[i]); 
    }
    max_val = max(max_val, val);

    val = 0;
    //裏表
    for(ll i = 1; i <= N; i++){
        if(A[i] <= 0 && B[i] >= 0) val += (B[i] - A[i]);
        if(A[i] > 0 && B[i] > 0 && B[i]-A[i] > 0) val += (B[i] - A[i]);
        if(A[i] < 0 && B[i] < 0 && B[i]-A[i] > 0) val += (B[i] - A[i]);
    }
    max_val = max(max_val, val);

    val = 0;
    //裏裏
    for(ll i = 1; i <= N; i++){
        if(A[i] <= 0 && B[i] <= 0) val -= (B[i] + A[i]);
        if(A[i] > 0 && B[i] < 0 && B[i]+A[i] < 0) val -= (B[i] + A[i]);
        if(A[i] < 0 && B[i] > 0 && B[i]+A[i] < 0) val -= (B[i] + A[i]);
    }
    max_val = max(max_val, val);

    cout << max_val << endl;
    return 0;


}