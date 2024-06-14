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
 ull mod = 1000000007;

ull inv_mod(ull a, ull b){
    ull p = a;
    ull ans = 1;
    for(ull i = 0; i <= 60; i++){
        if((b &(1LL << i)) != 0LL){
            ans *= p;
            ans %= mod;
        }
        p *= p;
        p %= mod;
    }
    return ans;
}

ull div_mod(ull a){
    return a%mod;
}

int main(){
    ull L, R;
    cin >> L >> R;

    ull L_dig = 1;
    ull R_dig = 1;

    ull val[19];
    val[1] = 10;
    for(ull i = 1; i <= 18; i++){
        if(L >= val[i]) L_dig ++;
        if(R >= val[i]) R_dig ++;
        if(i != 18)val[i+1] = val[i]*10;
    }
    ull cnt = 0;
    if(L_dig == R_dig){

        cnt += div_mod(L_dig*div_mod(div_mod((R+L))*div_mod((R-L+1)))*inv_mod(2, mod-2));
        cnt %= mod;
    }
    else{
        for(ull i = L_dig; i <= R_dig; i++){
            if(i == L_dig){
                cnt += L_dig*div_mod(div_mod(div_mod((R+L))*div_mod((R-L+1)))*inv_mod(2, mod-2));
                cnt %= mod;
            }else{
                cnt += div_mod(div_mod(div_mod(val[i-1] + R)*div_mod(R-val[i-1]+1))*inv_mod(2, mod-2));
                cnt %= mod;
            }
        }

    }
    cout << cnt << endl;
    return 0;

}