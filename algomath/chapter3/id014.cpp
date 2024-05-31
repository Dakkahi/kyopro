//N個の最大公約数を求めるプログラム
#include<iostream>
using namespace std;
using ll = long long;


int main(){
    ll N;
    cin >> N;

    bool isprime = true;

    for(ll i = 2; i*i <= N; i++){
        if(N % i == 0){
            isprime = false;
            break;
        }
    }
    if(isprime == true){
        cout << N << endl;
    }

    else{
        for(ll i= 2; i*i <= N; i++){
            while(N % i == 0){
                N = N/i;
                if(N == 1){
                    cout << i;
                }
                else{
                    cout << i << " ";
                }
            }
        }
        if(N > 1) cout << N;
    }
    return 0;
}