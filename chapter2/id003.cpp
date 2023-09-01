#include<iostream>
using namespace std;

int main(){
    int N , A[59];
    int ans = 0;
    cin >> N;
    for(int i = 1; i <=N; i++){
        cin >> A[i];
        ans += A[i];
    }
    cout << ans << endl;
    return 0;
}