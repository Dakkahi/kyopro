#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    //余事象を考える
    long long rest = 0;

    //2枚の差がK未満になるように書くのは何通り？
    for(int i = 1; i <= N; i++){
        for(int j = max(1, i-(K-1)); j <= min(N, i + (K-1)); j++){
            for(int k = max(1, i-(K-1));k <= min(N, (i + (K-1))); k++){
                if(abs(j - k) <= K-1) rest ++;
            }
        }
    }
    cout << (long long)N*N*N - rest << endl;
    return 0;
}