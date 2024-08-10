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
    ll d[N+1];
    for(ll i = 1; i <= N; i++) cin >> d[i];

    ll day = 7;
    ll seq = 0;
    ll seq_max = 0;
    ll start = 1;
    ll end = start+(day-1);
    ll off_cnt = 0;
    
    while(end <= N){
        if(seq == 0){
            off_cnt = 0;
            for(ll i = start; i <= end; i++){
                if(d[i] == 0) off_cnt ++;
            }
            if(off_cnt >= 2) seq = 7;
        }
        else{
            if(d[start-1] == 0) off_cnt --;
            if(d[end+1] == 0) off_cnt ++;
            
            if(off_cnt >= 2) seq ++;
            else{
                seq_max = max(seq_max, seq);
                seq = 0;
            }
        }
        start ++;
        end ++;
    }
    cout << seq_max << endl;
    return 0;
}