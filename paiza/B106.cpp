#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;
using ll = long long;

int main(){
    ll H, W, N;
    cin >> H >> W >> N;

    ll A[H*W+1];
    for(ll i = 1; i <= W*H; i++) A[i] = 0; //(i-1)*W + j
    ll s[N+1];
    for(ll i = 1; i<=N; i++) {
        cin >> s[i];
        A[s[i]] = i;
    }

    for(ll i = 2; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            if(A[(i-1)*W + j] != 0){
              ll cnt = 1;
              while(i-1-cnt >= 0 && A[(i-1-cnt)*W + j] == 0){
                A[(i-1-cnt)*W + j] = A[(i-cnt)*W + j];
                A[(i-cnt)*W + j] = 0;
                cnt ++;
              }
        }
    }
    }

    for(ll i = 1; i <= H*W; i++){
        if(i % W == 0) cout << A[i] << endl;
        else cout << A[i] << " ";
    }

    return 0;
}