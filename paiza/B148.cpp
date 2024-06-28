#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;
using ll = long long;


int main(){
    ll N;
    cin >> N;

    ll rate[N+1];
    vector<pair<ll, ll>> G;
    for(ll i = 1; i <= N; i++) {
        ll x;
        cin >> x;
        G.push_back(make_pair(i,x));
    }

    sort(G.begin(), G.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b){
        return a.second > b.second;
    });
    ll stack;
    for(ll i = 0; i < N; i++){
        if(i == 0){
            rate[G[i].first] = i+1;
            stack = i+1;
        }
        else{
            if(G[i].second == G[i-1].second){
                rate[G[i].first] = stack;
            }
            else{
                rate[G[i].first] = i+1;
                stack = i+1;
            }
        }
    }
    for(ll i = 1; i <= N; i++){
        cout << rate[i] << endl;
    }
    return 0;
}