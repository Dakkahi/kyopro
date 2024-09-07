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
    ll H, W, Q;
    cin >> H >> W >> Q;

    ll s[H+2][W+2];
    for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++) s[i][j] = 1; //s[i][j] = 1のとき，壁がある
    }

    ll cnt = H*W;

    for(ll q = 1; q <= Q; q++){
        ll R, C;
        cin >> R >> C;
        //壁を壊す
        if(s[R][C] == 1){
            s[R][C] = 0;
            cnt --;
        }
        else{
            ll dx = 0;
            ll dy = 0;
            //まずは右から
            while(s[R+dx][C] != 1 && R+dx <= H) dx++;
            if(s[R+dx][C] == 1){
                s[R+dx][C] = 0;
                cnt --;
            }

            //次は左
            dx = 0;
            while(s[R+dx][C] != 1 && R+dx >= 1) dx--;
            if(s[R+dx][C] == 1){
                s[R+dx][C] = 0;
                cnt --;
            }

            //上
            while(s[R][C+dy] != 1 && C+dy <= W) dy++;
            if(s[R][C+dy] == 1){
                s[R][C+dy] = 0;
                cnt --;
            }

            //下
            dy = 0;
            while(s[R][C+dy] != 1 && C+dy >= 1) dy--;
            if(s[R][C+dy] == 1){
                s[R][C+dy] = 0;
                cnt --;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}