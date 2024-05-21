#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){

    int N, Q;
    int num[100009];
    int A[100009], B[100009];
    int sum[100004];

    cin >> N >> Q;

    for(int k = 1; k <= N; k++){
        cin >> num[k];
    }

    for(int i = 1; i <= Q; i++){
        cin >> A[i] >> B[i];
    }
    sum[0] = 0;
    //j日目までの累積来場者数を格納して引き算をすれば計算量が小さくなって済む
    for(int j = 1; j <= N; j++){
       sum[j] = sum[j - 1] + num[j];
    }

    for(int r = 1; r <= Q; r++){
        cout << sum[B[r]] - sum[A[r]-1] << endl;
    }

    return 0;
}