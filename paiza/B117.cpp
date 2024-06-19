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
    ll N;
    cin >> N;
    ll A;
    queue<ll> Q;
    for(ll i = 1; i <= N; i++) {
        cin >> A;
        Q.push(A);

    }

    ll cnt = 0;
    ll flag = 1;
    while(!Q.empty()){
        ll head = Q.front();
        Q.pop();
        if(flag != head){
            Q.push(head);
            if(head == N){
                cnt++;
            }
        }
        else{
            flag += 1;
        }
    }
    cout << cnt << endl;
    return 0;
}