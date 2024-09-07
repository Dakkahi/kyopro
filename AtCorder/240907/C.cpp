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
    string S, T;
    cin >> S >> T;

    ll len = S.length();

    ll s[len], t[len], diff[len];
    ll minus_cnt = 0;
    ll plus_cnt = 0;
    for(ll i = 0; i < len; i++){
        s[i] = S[i];
        t[i] = T[i];
        diff[i] = s[i]-t[i];
        if(diff[i] < 0) minus_cnt ++;
        if(diff[i] > 0) plus_cnt ++;
    }

    cout << plus_cnt + minus_cnt << endl;


    ll idx = 0;
    while(plus_cnt > 0){
        idx %= len;
        if(diff[idx] <= 0) {
            idx++;
            continue;
        }

        if(diff[idx] > 0){
            S[idx] = T[idx];
            cout << S << endl;
            plus_cnt --;
            diff[idx] = 0;
        }

        // if(diff[idx] < 0){
        //     if(plus_cnt == 0) {
        //         S[idx] = T[idx];
        //         cout << S << endl;
        //         minus_cnt --;
        //         diff[idx] = 0;
        //     }
        // }
        idx ++;
    }


    idx = len-1;
    while(minus_cnt > 0){
        if(diff[idx] == 0) {
            idx = (idx+len-1)%len;
            continue;
        }
        // if(diff[idx] > 0){
        //     S[idx] = T[idx];
        //     cout << S << endl;
        //     plus_cnt --;
        //     diff[idx] = 0;
        // }

        if(diff[idx] < 0){
            S[idx] = T[idx];
            cout << S << endl;
            minus_cnt --;
            diff[idx] = 0;
        }
        idx = (idx + len - 1)%len;
    }
    return 0;
}