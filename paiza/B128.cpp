#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;

    string S = to_string(N);
    ll digit = S.length();


    string qr[digit][9];
    for(ll i = 0; i < digit; i++){
        for(ll j = 0; j < 9; j++) qr[i][j] = '.';
    }

    for(ll i = 0; i < S.length(); i++){
        ll val = S[i] - '0';
        for(ll j = 0; j < digit; j++)
            qr[(i/3)*3 + j/3][(i%3)*3 + j%3] = '#';
    }

    for(ll i = 0 ; i < digit; i++){
        for(ll j = 0; j < 9; j++){
            if((j+1)%9 == 0) cout << qr[i][j] << endl;
            else cout << qr[i][j] << " ";
        }
    }
    return 0;
}