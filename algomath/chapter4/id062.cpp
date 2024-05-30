#include <iostream>
#include<vector>
using namespace std;

int main(){
    long long N, K;
    cin >> N >> K;
    vector<long long> A(N+1);
    for(long long i = 1; i <= N; i++) {
        cin >> A[i];
    }
    long long pos = 1;
    
    for(long long i = 1; i <= N; i++){
        pos = A[pos];
    }

    if(N >= K){
        pos = 1;
        for(long long i = 1; i <= K; i++){
            pos = A[pos];
        }
        cout << pos << endl;
    }
    else{
        long long start_pos = pos;
        long long travel = K - N;
        long long cnt = 1; //ループに含まれるノードの数
        pos = A[pos];
        while(pos != start_pos){
            cnt ++;
            pos = A[pos];
        }
        long long div = travel%cnt;
        //cout << cnt << endl;
        if(div == 0) cout << start_pos << endl;
        else{
            for(long long i = 1; i <= div; i++){
                pos = A[pos];
            }
            cout << pos << endl;
        }
    }
    return 0;
}