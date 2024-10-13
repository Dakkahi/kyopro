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
using ull = unsigned long long;

int main(){
    ull N, D;
    cin >> N >> D;
    ull A[N+1];
    for(ull i = 1; i <= N; i++) cin >> A[i];

    //全事象から引いた方が早い
    ull seq[1LL << N];
    ull bit_cnt[1LL << N];
    ull ele_num[1LL << N];
    for(ull i = 0; i < (1LL << N); i++) {
        seq[i] = 0;
        bit_cnt[i] = 0;
        ele_num[i] = 0;
    }

    for(ull i = 0; i < (1LL << N); i++){ 
        for(ull j = 1; j <= N; j++){
            if((i & (1LL << (j-1))) != 0LL){
                seq[i] = (seq[i] | A[j]);
                ele_num[i] += 1;
            }
        }
    }

    for(ull i = 0; i < (1LL << N); i++){ 
        for(ull j = 1; j <= D; j++){
            if((seq[i] & (1LL << (j-1))) == 0LL){
                bit_cnt[i] += 1;
            }
        }
    }

    ull ans = 0;

    for(ull i = 0; i < (1LL << N); i++){
        if(ele_num[i]%2 == 0){
            ans += 1LL << bit_cnt[i];
        }else{
            ans -= 1LL << bit_cnt[i];
        }
    }

    cout << ans << endl;
    return 0;
}