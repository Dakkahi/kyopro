#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;
vector<ll>  a;

ll binary_search(ll l, ll r, ll x){
    while(l<r){
        ll center = (l+r)/2;
        if(a[center] < x) l = center+1;
        else if(a[center] > x) r = center-1;
        else{
            return center;
        }
    }
    return l;
}
int main(){
    ll N, X;
    cin >> N >> X;
    for(ll i = 0; i < N; i++){
        ll in;
        cin >> in;
        a.push_back(in);
    } 

    sort(a.begin(), a.end());

    ll M = a[a.size()-1];

    bool flag = true;
    ll cnt = 0;
    while(X <= M){
        ll idx = binary_search(0, a.size()-1, X);
        if(idx == 0 && X < a[idx]){
            cnt = -1;
            break;
        }
        else{
            if(idx == 0){
            X += a[idx];
            a[idx] = 0;
        }else{
            X += a[idx-1];
            a[idx-1] = 0;
        }
            sort(a.begin(), a.end());
            M = a[a.size()-1];
            cnt ++;
        }
    }
    cout << cnt << endl;
    return 0;
}