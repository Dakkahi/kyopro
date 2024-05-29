//最小公倍数を求めるプログラム
#include<iostream>
using namespace std;


long long GCD(long long A, long long B){
    while(A >= 1 && B >= 1){
        if (A < B) B = B%A;
        else A = A%B;
    }
    if(A >= 1) return A;
    return B;
}

long long LCM(long long A, long long B){
    long long gcd = GCD(A,B);
    return A*B/gcd;
}

int main(){
    long long N, A[100];
    cin >> N;
    for(long long i=1; i <= N; i++) cin >> A[i];

    long long ans = A[1];
    for(long long i = 1; i <= N; i++){
        ans = LCM(ans, A[i]);
    }
    cout << ans << endl;
    return 0;
}