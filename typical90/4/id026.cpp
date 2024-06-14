#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ll N;
    cin >> N;
    ll A[N], B[N];
    vector<ll> G[N+1];
    ll color[N+1];
    fill(color, color+N+1, -1);
    color[1] = 0;
    for(ll i = 1; i <= N-1; i++){
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    queue<ll> Q;
    Q.push(1);
    while(!Q.empty()){
        ll head = Q.front();
        Q.pop();
        for(ll i :G[head]){
            if(color[i] == -1){
                Q.push(i);
                color[i] = (color[head]+1)%2;
            }
        }
    }
    vector<ll> red;
    vector<ll> blue;
    for(ll i = 1; i <= N; i++) {
        if(color[i] == 1) red.push_back(i);
        else blue.push_back(i); 
        
    }
    if(red.size()>= N/2){ //color[i] = 1のものを取り出す
        for(ll i = 0; i < N/2; i++){
            cout << red[i] << " ";
        }
    }
    else{
        for(ll i = 0; i < N/2; i++){
            cout << blue[i] << " ";
        }
    }
    cout << endl;
    return 0;

}