#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ll N, L;
    cin >> N >> L;
    ll K;
    cin >> K;
    ll A[N+1];
    ll B[N+1]; //階差
    A[0] = 0;
    B[0] = 0;
    for(ll i = 1; i <= N; i++) {
        cin >> A[i];
        B[i] = A[i] - A[i-1];
    }

    //スコアの二分探索を行う
    ll l = 1;
    ll r = L;
    ll length;
    ll ans = 0;
    //二分探索
    while(l <= r){
        length = (l+r)/2;

        //lengthが最小となるように羊羹を切ることができるかを試す
        ll cut = 0;
        ll current_len = 0;
        for(ll i = 1; i <= N; i++){
            current_len += B[i];
            if(current_len >= length && L - A[i] >= length){
                cut++;
                current_len = 0;
            }
        }

        if(cut < K){
            //失敗の処理
            r = length - 1;
        }
        else{
            //成功処理
            l = length+1;
            ans = length;
        }
    }

    cout << ans << endl;
    return 0;

}