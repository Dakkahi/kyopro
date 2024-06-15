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
    ll N = 1022221200;
    ll min = 10000;
    ll max = 99999;
    vector<ll>G;

    for(ll i = 1; i*i <= N; i++){
        if(N%i == 0){
            G.push_back(i);
            if(i*i != N){
                G.push_back(N/i);
            }
        }
    }
    ll cnt = 0;
    for(ll i = 0; i < G.size(); i++){
        if(min <= G[i] && G[i] <= max) cnt ++;
    }
    cout << cnt << endl;
    return 0;
    

}