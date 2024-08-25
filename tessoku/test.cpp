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
    double x = 0.98;
    ll cnt;
    for(ll i = 1; i <= 100; i++){
        if(x <= 0.5){
            cnt = i;
            break;
        }
        x *= 0.98;
    }
    cout << cnt << endl;
    return 0;
}