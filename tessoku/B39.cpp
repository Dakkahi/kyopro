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
    ll N, D;
    cin >> N >> D;
    ll X[N+1], Y[N+1];
    pair<ll, ll> task[N+1]; //(day, -money)の組み合わせ
    for(ll i = 1; i <= N; i++){
        cin >> X[i] >> Y[i];
        task[i].first = X[i];
        task[i].second = -Y[i];
    }

    sort(task+1, task+N+1);

    ll money = 0;
    ll idx = 1;
    for(ll i = 1; i <= D; i++){
        while(i < task[idx].first && idx <= N) idx++;
        if(idx <= N){
            ll extension = 0;
            money -= task[idx].second;
            idx ++;
        }
    }

    cout << money << endl;
    return 0;
}