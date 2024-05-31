//N個の最大公約数を求めるプログラム
#include<iostream>
using namespace std;
using ll = long long;

int main(){
    long long A, B;
    cin >> A >> B;

    while(A != 0 && B != 0){
        if(A > B) A = A%B;
        else B = B%A;
    }
    if(A == 0) cout << B << endl;
    else cout<< A << endl;
    return 0;
}