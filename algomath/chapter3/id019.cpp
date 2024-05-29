#include<iostream>
using namespace std;

int main(){
    int N, A[500001], a, b, c, ans;
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    for(int i = 1; i <= N; i++){
        if(A[i] == 1) a++;
        if(A[i] == 2) b++;
        if(A[i] == 3) c++;
    }
    ans = (a*(a-1) + b*(b-1) + c*(c-1))/2;
    cout << ans << endl;
    return 0;

}