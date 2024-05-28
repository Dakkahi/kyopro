#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
using namespace std;

int main(){
    long long H, W, N, T;
    cin >> H >> W;
    cin >> N >> T;

    if(H*W <= T){
        cout << N << endl;
        return 0;
    }
    else{
    long long A[H*W+1]; //各エリアにいるネズミの数を調べ上げる
    for(long long i = 1; i <= H*W; i++){
       A[i] = 0;
    }
    A[0] = 0;

    long long x[N+1], y[N+1];
    for(long long i = 1; i <= N; i++) {
        cin >> x[i] >> y[i]; //ネズミの座標
        A[(x[i]-1)*W + y[i]] += 1;
    }//Aに各座標におけるネズミの数を格納

    long long sum = 0;
    for(int t = 1; t <= T; t++){
        long long max = 0;
        long long index = 0;
        for(int r = 1; r <= H*W; r++){
            if(max <= A[r]){
                max = A[r];
                index = r;
            }
        }
        sum += max;
        A[index] = 0;
    }
        cout << sum << endl;
    }


    return 0;

}