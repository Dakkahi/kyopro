#include <iostream>
#include<vector>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    int A[N+1];
    int sum = 0;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    if(sum > K) cout << "No" << endl;

    else{
        if((sum - K)%2 == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}