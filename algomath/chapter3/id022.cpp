#include<iostream>
using namespace std;

int main(){
    int N, A[1000000];
    cin >> N;
    int ans;

    for(int i = 1; i <= N; i++) cin >> A[i];
    for(int i = 1; i <= N; i++){
        for(int j = i + 1; j <= N; j++){
            if(A[i] + A[j] == 100000) ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}

