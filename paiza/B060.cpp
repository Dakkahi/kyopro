#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    ll N, H, W;
    cin >> N >> H >> W;
    ll sy, sx;
    cin >> sy >> sx;
    string s;
    cin >> s;

    ll M[H+1][W+1];
    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++) M[i][j] = 0;
    }
    ll bottom = 6;
    ll front = 5;
    ll right = 4;
    M[sy][sx] = bottom;
    for(ll i = 0; i < N; i++){
        char dir = s[i];
        if(dir == 'U'){
            sy --;
            ll bottom_stack = bottom;
            bottom = 7 - front;
            ll front = bottom_stack;
            M[sy][sx] = bottom; 
        }
        if(dir == 'D'){
            sy ++;
            ll bottom_stack = bottom;
            bottom = front;
            front = 7 - bottom_stack;
            M[sy][sx] = bottom;
        }
        if(dir == 'R'){
            sx ++;
            ll bottom_stack = bottom;
            bottom = right;
            right = 7 - bottom_stack;
            M[sy][sx] = bottom;
        }
        if(dir == 'L'){
            sx --;
            ll bottom_stack = bottom;
            bottom = 7 - right;
            right = bottom;
            M[sy][sx] = bottom;
        }
    }
    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            if(j == W) cout << M[i][j] << endl;
            else cout << M[i][j];
        }
    }
    return 0;
}