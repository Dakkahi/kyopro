#include<iostream>
using namespace std;

int N, A[200009];

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];

    //選択ソート
    for(int i = 1; i <= N - 1; i++){
        int min_val = i;
        for(int j = i+1; j <= N; j++){
            if (A[min_val] > A[j]) min_val = j;
        }
        swap(A[i], A[min_val]);
    }

    for(int i = 1; i <= N; i++) cout << A[i] << endl;
    return 0; 
}