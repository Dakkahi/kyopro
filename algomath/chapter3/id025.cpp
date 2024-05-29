#include<iostream>
using namespace std;

int main(){
    int N, A[60], B[60];
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i] >> B[i];

    double exp_val = 0;
    for(int i = 0; i <= N; i++){
        exp_val += 2*B[i]/3 + A[i]/3;
    }

    cout << exp_val << endl;
    return 0;
}