#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
//using ll = long long;



int main(){
    int N;
    cin >> N;
    double a[N+1], b[N+1], c[N+1];
    for(int i = 1; i <= N; i++) cin >> a[i] >> b[i] >> c[i];

    double ans = 0.0;
    for(int i = 1; i < N; i++){
        for(int j = i+1; j <= N; j++){
            if(a[i]*b[j] == a[j]*b[i]) continue;

            double bunbo = a[i]*b[j] - a[j]*b[i];
            double x = (b[j]*c[i]-b[i]*c[j])/bunbo;
            double y = (-a[j]*c[i]+a[i]*c[j])/bunbo;
            bool flag = true;
            for(int k = 1; k <= N; k++){
                if(a[k]*x + b[k]*y > c[k]){
                    flag = false;
                    break;
                }
            }
            if(flag == true) ans = max(ans, x+y);
            }
        }
    
    //切片の処理
    for(int i = 1; i <= N; i++){
        double x_edge = c[i]/a[i];
        double y_edge = c[i]/b[i];
        bool flag_x = true;
        bool flag_y = true;
        for(int k = 1; k<= N; k++){
            if(x_edge*a[k] > c[k]) flag_x = false;
            if(y_edge*b[k] > c[k]) flag_y = false;
            if(flag_x == false && flag_y == false) break;
        }
        if(flag_x == true) ans = max(ans, x_edge);
        if(flag_y == true) ans = max(ans, y_edge);
    }
    printf("%.12lf\n", ans);
    return 0;
}