#include<iostream>
using namespace std;

int main(){
    int N, B[110], R[110];
    for(int i = 1; i <= N; i++) cin >> B[110];
    for(int i = 1; i <= N; i++) cin >> R[110];

    double exp_val = 0.0;
    for(int i = 1; i <= N; i++){
        exp_val += B[i] + R[i];
    }
    cout << exp_val << endl;
    return 0;
}