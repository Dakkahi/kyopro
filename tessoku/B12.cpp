#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

double func(double x){
    return x*x*x + x;
}

int main(){

    ll N;
    cin >> N;

    double l = 1;
    double r = N;
    double x;

    while(abs(r-l) > 0.0001){
        x = (l+r)/2;
        if(func(x) < N) l = x+0.0001;
        else r = x;
    }

    cout << l << endl;
    return 0;
}