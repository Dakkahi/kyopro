//高速プログラム
#include<iostream>
using namespace std;

bool isprime(long long N){
    for(long long i = 2; i*i <= N; i++){
        if (N % i == 0) return false;
    }
    return true;
}

int main(){
    long long N;
    cin >> N;
    bool test = isprime(N);
    cout << test << endl;
    return 0;
}