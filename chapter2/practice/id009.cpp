#include<iostream>
using namespace std;

long long N, S, A[61];

int main(){
    cin >> N >> S;
    for(int i = 1; i <= N; i++) cin >> A[i];

    //全パターン探索(ビット全探索)
    for(long long i = 0; i < (1LL << N); i++){//1LL << Nでbitをずらしたことになって2^Nに対応
        long long sum = 0;
        for(int j = 1; j <= N; j++){
            if((i & (1LL<<(j-1))) != 0LL) sum += A[j];
        }
        if(sum == S){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;

}