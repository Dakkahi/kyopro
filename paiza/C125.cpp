#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int max = 1;
    int A[N+4], B[N+4];
    for(int i = 1; i <= N; i++){
        cin >> A[i];
        max = max*6;
    }
    max = -max;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int num = 1;
            if(i != j){
                A[i] = A[i] + 1;
                A[j] = A[j] - 1;
            }
            for(int k = 1; k <= N; k++){
                num = num*A[k];
            }
            if(num > max) {
                max = num;
            }
            A[i] = A[i] - 1;
            A[j] = A[j] + 1;
        }
    }
    cout << max << endl;
    return 0;
}