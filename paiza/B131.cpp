#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
using namespace std;

int main(){
    int N, M, X;
    cin >> N >> M;
    int A[N*M+1];
    for(int i = 1; i<=N; i++){
        for(int j = 1; j <= M; j++) cin >> A[j+(i-1)*M];
    }
    //int pos_r = 1; 
    cin >> X;
    int pos_sta = 1;
    int val = 0; //値段
    int R[X+1], S[X+1];
    for(int  i = 1; i <= X; i++){
        cin >> R[i] >> S[i];
        cout << (R[i] - 1)*M + S[i] << endl;
        val += abs(A[(R[i] - 1)*M + S[i]] - A[(R[i] - 1)*M+pos_sta]);
        pos_sta = S[i];
    }
    cout << val << endl;
    return 0;
}