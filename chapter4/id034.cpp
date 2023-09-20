#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

long long N, x[1000009], y[1000009];
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> x[i] >> y[i];
    }
    long long norm = 1LL << 60;
    for(int i = 1; i < N; i++){
        for(int j = i+1;  j<=N; j++){
            if (norm > (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])) norm = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
        }
    }
    double ans = sqrt(norm);
    printf("%.12lf\n", ans);
    return 0;
}