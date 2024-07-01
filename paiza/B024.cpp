#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;


int main(){
    double r;
    cin >> r;

    ll len = r/1+1;
    ll cnt = 0;
    for(ll i = 0; i < len; i++){
        for(ll j = 0; j < len; j++){
            if(i*i + j*j < r*r) cnt ++;
        }
    }
    cout << cnt*4 << endl;
    return 0;
}