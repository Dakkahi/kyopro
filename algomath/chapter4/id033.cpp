#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

//点と直線の距離は平行四辺形の面積から底辺を割れば良い

//内積を計算する関数


int main(){

    long long ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    //線分との距離は線分と点の位置関係で変わる
    int pattern = 2;
    if((ax-bx)*(cx-bx) + (ay-by)*(cy-by) < 0LL) pattern = 1;
    if((ax-cx)*(bx-cx) + (ay-cy)*(by-cy) < 0LL) pattern = 3;

    double ans = 0.0;
    if(pattern == 1) ans = sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
    if(pattern == 3) ans = sqrt((ax-cx)*(ax-cx) + (ay-cy)*(ay-cy));
    if(pattern == 2){
        double S = abs((ax-bx)*(cy-by) - (ay-by)*(cx-bx));
        double BCLength = sqrt((bx-cx)*(bx-cx) + (by-cy)*(by-cy));

        ans = S / BCLength;
    }

    printf("%.12lf\n", ans);
    return 0;
}