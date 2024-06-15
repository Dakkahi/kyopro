#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;


//ピタゴラスの三角形は3, 4, 5と5, 12, 13
int main(){
    ll m = 1;
    ll val = 16000;
    ll sq = 500;
    ll cnt = 0;
    for(ll i = 3; i <= sq; i++){
        for(ll j = i+1; j <= sq; j++){
            if(i*j <= val){
                for(ll k = j+1; k <= i+j; k++)
                if(k*k == i*i + j*j) cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}