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
    int a[N+1][N+1];
    for(ll i  =1; i <= N; i++){
        for(ll j = 1; j <= N; j++) cin >> a[i][j];
    }
    ll r,c,s,d;
    cin >> r >> c >> s >> d;

    ll rotate = (d/90)%4;

    ll stack[s+1][s+1];

    while(rotate != 0){
    for(ll i = 1; i <= s; i++){
        for(ll j = 1; j <= s; j++){
            stack[i][j] = a[r+i-1][c+j-1];
        }
    }

    for(ll i = 1; i <= s; i++){
        for(ll j = 1; j <= s; j++){
            a[r+j-1][c+s-i] = stack[i][j];
        }
    }
    
    rotate --;
    }

    for(ll i  =1; i <= N; i++){
        for(ll j = 1; j <= N; j++){
            if(j%N == 0) cout << a[i][j] << endl;
            else cout << a[i][j] << " ";
        }
    }
    return 0;
}