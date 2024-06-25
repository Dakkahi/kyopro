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
    ll sx, sy, tx, ty;
    cin >> sx >> sy;
    cin >> tx >> ty;



    ll x = abs(tx-sx);
    ll y = abs(ty-sy);

    ll pay = y;
    if(x/2+1 > y){
        if((x-y)%2 == 0){
            pay += (x-y)/2;
        }
        else{
           if((sx+sy)%2 == 0){
            pay += (x-y)/2;
           }
           else{
            pay += (x-y)/2+1;
           }
        }

    }
    

    cout << pay << endl;

    return 0;
}