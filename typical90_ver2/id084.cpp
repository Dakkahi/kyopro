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
    ll N;
    cin >> N;
    string S;
    cin >> S;

    ll cnt_cir[N+1];
    ll cnt_rec[N+1];

    for(ll i = 0; i <= N; i++){
        cnt_cir[i] = 0;
        cnt_rec[i] = 0;
        if(i > 0){
            if(S[i-1] == 'o'){
                cnt_cir[i] = cnt_cir[i-1] + 1;
                cnt_rec[i] = cnt_rec[i-1];
            }
            else {
                cnt_rec[i] = 1 + cnt_rec[i-1];
                cnt_cir[i] = cnt_cir[i-1];
            }
        }
        //cout << cnt_cir[i] << " " << cnt_rec[i] << endl;
    }
    ll cnt = 0;

    for(ll i = 1; i <= N; i++){
        ll cir_idx = lower_bound(cnt_cir+i, cnt_cir+N+1, 1+cnt_cir[i-1]) - cnt_cir;
        ll rec_idx = lower_bound(cnt_rec+i, cnt_rec+N+1, 1+cnt_rec[i-1]) - cnt_rec;

        ll idx = max(cir_idx, rec_idx);
        cnt += N-idx+1;
        //cout << cir_idx << " " << rec_idx << endl;
    }
    cout << cnt << endl;
    return 0;

}