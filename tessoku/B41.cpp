#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    ll X, Y;
    cin >> X >> Y;

    stack<pair<ll, ll> > S;

    bool flag = false;

    if(X == 1 && Y == 1) flag = true;

    ll cnt = 0;
    
    while(flag == false){
        S.push(make_pair(X, Y));
        if(X > Y) X -= Y; 
        else Y -= X;

        if(X == 1 && Y == 1) flag = true;
        cnt ++;
    }

    cout << cnt << endl;
    while(!S.empty()){
        pair<ll, ll> head = S.top();
        S.pop();
        cout << head.first << " " << head.second << endl;
    }
    return 0;
}