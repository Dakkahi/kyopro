#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;


int main(){
    ll N, Q;
    cin >> N;
    ll score[2001];
    for(ll i = 0; i <= 2000; i ++) score[i] = 0;
    ll t, d, s;
    for(ll i = 1; i <= N; i++){
        cin >> t >> d >> s;
        score[t] += s;
        score[t+d] -= s;
    }
    cin >> Q;

    for(ll i = 1; i <= 2000; i++){
        if(i > 1){
            score[i] += score[i-1];
        }
    }
    ll q;
    for(ll i = 1; i <= Q; i++) {
        cin >> q;
        cout << score[q] << endl;
    }
    

    return 0;
}