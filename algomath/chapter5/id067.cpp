#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    long long H, W;
    cin >> H >> W;

    long long A[H*W+1];
    long long B[H*W+1];

    long long h[H*W+1]; //H行
    long long w[W*H+1]; //W列
    for(int i = 1; i <= H*W; i++) {
        cin >> A[i]; //i行j列は (i-1)*W + j
        h[i] = 0;
        w[i] = 0;
    }

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            h[i] += A[(i-1)*W + j];
        }
    }

    for(int i = 1; i <= W; i++){
        for(int j = 1; j <= H; j++){
            w[i] += A[(j-1)*W + i];
        }
    }

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            B[(i-1)*W + j] = h[i] + w[j] - A[(i-1)*W + j];
        }
    }

    for(int i = 1; i <= H*W; i++){
        if(i%W == 0) cout << B[i] << endl;
        else cout << B[i] << " ";
    }

    return 0;

}