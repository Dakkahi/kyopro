//最大公約数を鈍臭く求める
#include<iostream>
using namespace std;

long long GCD(long long A, long long B){
    long long ans = 0;
    for(long long i = 1; i<= min(A,B); i++){
        if(A%i == 0 && B%i == 0) ans = i;
    }
    return ans;
}

int main(){
    long long A, B;
    cin >> A >> B;
    long long gcd;
    gcd = GCD(A, B);
    cout << gcd << endl;
    return 0;

}