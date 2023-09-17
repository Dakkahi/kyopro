#include<iostream>
using namespace std;

long long GCD(long long A, long long B){
    if(B == 0) return A;
    return GCD(B, A%B);
}

int main(){
    long long N, M;
    cin >> N >> M;
    long long ans = GCD(N, M);
    cout << ans << endl;
    return 0;
}