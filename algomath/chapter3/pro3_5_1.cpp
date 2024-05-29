#include<iostream>
using namespace std;

int main(){
    int N = 1000000;
    int M = 0;

    for(int i = 1; i <= N; i++){
        double px = rand()/ (double)RAND_MAX; //0以上1以下にする.
        double py = rand()/ (double)RAND_MAX;

        if(px*px + py*py <= 1) M+= 1;
    }
    printf("%.12lf\n", 4.0*M/N);
    return 0;
}