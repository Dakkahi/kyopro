#include <iostream>
using namespace std;

int main(){
    long long a, b;
    cin >> a >> b;
    long long mod = 1000000007;

    //bを二進数の和で表現して，そのあまりを計算すれば良さそう
    //まず，bが二進法でどのように表されるのかを知る必要あり
    long long ans = 1;
    long long p = a;

    for(long long i = 0; i <= 30; i++){
        if((b & (1 << i)) != 0){
            ans *= p;
            ans %= mod;
        }
        p *= p;
        p %= mod;
    }

    cout << ans << endl;
    return 0;

}