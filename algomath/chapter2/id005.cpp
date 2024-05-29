#include<iostream>
using namespace std;

int main(){
    int N, A[10000], sum;
    sum = 0;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    int ans = sum%100;
    cout << ans << endl;
    return 0;
}