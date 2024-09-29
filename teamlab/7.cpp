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
    //10文字になるケースを考える
    //886はDCCCLXXXVIで10文字
    ll N = 1000;
    ll moji[N+1];
    ll cnt = 0;


    for(ll i = 1; i <= N; i++){
        moji[i] = 0;
        string let = to_string(i);
        for(ll j = 0; j < let.length(); j++){
            if(let[j] == '1' || let[j] == '5') moji[i]++;
            if(let[j] == '2' || let[j] == '4' || let[j] == '6' || let[j] == '9') moji[i] += 2;
            if(let[j] == '3' || let[j] == '7' ) moji[i] += 3;
            if(let[j] == '8') moji[i] += 4;  
        }
        if(moji[i] == 10) {
            cnt++;
            //cout << let << endl;
        }
    }

    cout << cnt << endl;

    
    return 0;
}