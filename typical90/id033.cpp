#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
using namespace std;
using ll = long long;

int main(){
    ll H, W;
    cin >> H >> W;
    ll half_h = (H+1)/2;
    ll half_w = (W+1)/2;

    if(H == 1 || W == 1){
        cout << H*W << endl;
    }
    else{
    cout << half_h*half_w << endl;
    }
    return 0;
}