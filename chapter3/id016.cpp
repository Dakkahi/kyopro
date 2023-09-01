//N個の最大公約数を求めるプログラム
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

int main(){
    long long N, A[100];
    cin >> N;
    for(long long i = 1; i <= N; i++) cin >> A[i];
    long long ans = A[1];

    for(long long i = 1; i <= N; i++){
        ans = GCD(ans, A[i]);
    }
    cout << ans << endl;
    return 0;
}