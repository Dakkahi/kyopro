#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    ll last = 0;
    ll A[N+1], B[N+1];
    for(ll i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
        last = max(last, B[i]);
    }
    ll day[last + 2];
    for(ll i = 1; i <= last+1; i++) {
        day[i] = 0;
    }

    for(ll i = 1; i <= N; i++){
        day[A[i]] += 1;
        day[B[i]+1] -= 1;
    }

    for(ll i = 1; i <= last; i++){
        if(i >= 2){
            day[i] += day[i-1];
        }
    }

    ll cnt_max = 0;

    ll cnt = 0;
    for(ll i = 1; i <= last; i++){
        if(day[i] > 0) cnt++;
        else{
            cnt_max = max(cnt, cnt_max);
            cnt = 0;
        }
    }
    cnt_max = max(cnt, cnt_max);
    cout << cnt_max << endl;
    return 0;

}