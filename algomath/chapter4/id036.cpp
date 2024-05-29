#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;

int main(){
    long long A, B, H, M;
    cin >> A >> B >> H >> M;

    double beta = M*M_PI/30;
    double alpha = H*M_PI/6 + M*M_PI/360;

    double theta = beta - alpha;

    double ans = sqrt(A*A + B*B - 2*A*B*cos(theta));

    printf("%.12lf\n", ans);
    return 0;
}