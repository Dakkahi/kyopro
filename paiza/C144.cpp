#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int cnt = 0;
    char A[N+4], B[N+4];
    for(int i = 1; i <= N; i++){
        cin >> A[i] >> B[i];
        if(A[i] == 'G' && B[i] == 'C' || A[i] == 'C' && B[i] == 'P' || A[i] == 'P' && B[i] == 'G'){
            cnt ++;
        }
    }
    cout << cnt << endl;
    return 0;
}