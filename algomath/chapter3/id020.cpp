#include<iostream>
using namespace std;

int N, A[200];
int ans = 0;

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];

    for(int i = 1; i<= N; i++){
        for(int j = i + 1; j<= N; j++){
            for(int k = j + 1; k<= N; k++){
                for(int l = k + 1; l<= N; l++){
                    for(int m = l + 1; l<= N; l++){
                        if(A[i] + A[j] + A[k] + A[l] + A[m] == 1000) ans ++;
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;

}