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
    ll a, b, c, d, e, f, g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f;
    cin >> g >> h >> i >> j >> k >> l;

    //長方形の8点は一位に定められる
    vector<ll> v1 = {a,b,c};
    vector<ll> v2 = {d,b,c};
    vector<ll> v3 = {a,e,c};
    vector<ll> v4 = {d,e,c};
    vector<ll> v5 = {a,b,f};
    vector<ll> v6 = {d,b,f};
    vector<ll> v7 = {a,e,f};
    vector<ll> v8 = {d,e,f};

    vector<ll> w1 = {g,h,i};
    vector<ll> w2 = {j,h,i};
    vector<ll> w3 = {g,k,i};
    vector<ll> w4 = {j,k,i};
    vector<ll> w5 = {g,h,l};
    vector<ll> w6 = {j,h,l};
    vector<ll> w7 = {g,k,l};
    vector<ll> w8 = {j,k,l};
    

    vector<ll> v[8] = {v1, v2, v3, v4, v5, v6, v7, v8};

    vector<ll> w[8] = {w1, w2, w3, w4, w5, w6, w7, w8};
    bool flag = false;

    for(ll i = 0; i < 8; i++){
        vector<ll> vec = v[i];
        if((vec[0]-g)*(vec[0]-j) < 0 && (vec[1]-h)*(vec[1]-k) < 0 && (vec[2]-i)*(vec[2]-l) < 0) flag = true;
    }

    for(ll i = 0; i < 8; i++){
        vector<ll> vec = w[i];
        if((vec[0]-a)*(vec[0]-d) < 0 && (vec[1]-b)*(vec[1]-e) < 0 && (vec[2]-c)*(vec[2]-f) < 0) flag = true;
    }


    if(flag == true) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

