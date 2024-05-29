#include<iostream>
#include<algorithm>
using namespace std;

int N, A[200009];

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];

    sort(A + 1, A + N + 1); //開区間[1,N+1)をソートする
    for(int i = 1; i <= N; i++) cout << A[i] << endl;
    return 0;
}