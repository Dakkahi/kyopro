#include<iostream>
using namespace std;

int N, A[20009];

int solve(int l, int r){
    if(r - l == 1) return A[l];
    int m = (l + r)/2;
    int s1 = solve(l, m);
    int s2 = solve(m,r);
    return s1 + s2;
}

int main(){
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];

    int ans = solve(1,N + 1);
    cout << ans << endl;
    return 0;
}