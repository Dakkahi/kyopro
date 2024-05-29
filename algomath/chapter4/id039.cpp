#include<iostream>
using namespace std;

int main(){
    int N, Q;
    int L[100009], R[100009], X[100009];
    int B[100009] = {0};


    cin >> N >> Q;
    for(int i = 1; i <= Q; i++){ cin >> L[i] >> R[i] >> X[i];
        B[L[i]] += X[i];
        B[R[i]+1] -= X[i];
    }
    //隣との差だけを見れば良いので端の処理だけをしていけば良い


    for(int k = 2; k <= N; k++){
        if(B[k] > 0) cout << "<";
        if(B[k] == 0) cout << "=";
        if(B[k] < 0) cout << ">";
    }
    cout << endl;
    return 0;

}