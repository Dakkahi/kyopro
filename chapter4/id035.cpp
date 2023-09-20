#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    long long x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;

    int ans = 0;
    long long norm = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);

    if((r1-r2)*(r1-r2) > norm) ans = 1;
    if((r1-r2)*(r1-r2) == norm) ans = 2;
    if((r1-r2)*(r1-r2) < norm  && norm < (r1+r2)*(r1+r2)) ans = 3;
    if((r1+r2)*(r1+r2) == norm) ans = 4;
    if((r1+r2)*(r1+r2) < norm) ans = 5;

    cout << ans << endl;
    return 0;
}