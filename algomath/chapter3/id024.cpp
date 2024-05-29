#include<iostream>
using namespace std;

int main(){
    int N, P[100], Q[100];
    for(int i = 1; i <= N; i++) cin >> P[i] >> Q[i];

    double exp_val = 0.0;
    for(int i = 1; i <= N; i++){
        exp_val += Q[i]/P[i];
    }

    cout << exp_val << endl;
    return 0;

}