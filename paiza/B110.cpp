#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    ll H, W;
    cin >> H >> W;

    ll A[H+1][W+1];
    ll B[H+1][W+1];

    ll A_large[2*H+1][2*W+1];
    ll B_large[2*H+1][2*W+1];

    ll Image[2*H][2*W];

    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++) {
            cin >> A[i][j];
            A_large[2*i-1][2*j-1] = A[i][j];
            A_large[2*i-1][2*j] = A[i][j];
            A_large[2*i][2*j-1] = A[i][j];
            A_large[2*i][2*j] = A[i][j];
        }
    }

    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++) {
            cin >> B[i][j];
            B_large[2*i-1][2*j-1] = B[i][j];
            B_large[2*i-1][2*j] = B[i][j];
            B_large[2*i][2*j-1] = B[i][j];
            B_large[2*i][2*j] = B[i][j];
        }
    }


    for(ll i = 1; i <= 2*H-1; i++){
        for(ll j = 1; j <= 2*W-1; j++){
            Image[i][j] = (A_large[i+1][j+1] + B_large[i][j])/2;
            //cout << Image[i][j] << " ";
            if(j == 2*W-1) cout << Image[i][j] << endl;
            else cout << Image[i][j] << " ";
        }
    }

    return 0;
}