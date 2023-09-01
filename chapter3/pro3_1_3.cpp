//約数出力プログラム
#include<iostream>
using namespace std;

int main(){
    long long N;
    cin >> N;

    for(long long i= 1; i*i <= N; i++){
        if(N % i != 0) continue;
        cout << i<< endl;

        if(i != N/i){
            cout << N/i << endl;
        }
    }
    return 0;
}