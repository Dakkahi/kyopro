#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    int A[N+1];
    ll B[N+1]; //方針として左に行くほど数値が大きくなるようにする
    ll G[N+1]; //Gには出力する答えを格納
    for(ll i = 1; i <= N; i++) {
        cin >> A[i];
        B[i] = 0;
    }

    //配列にいくつの数字が格納されているかを表す変数
    int tail = 0;
    for(ll i = 1; i <= N; i++){
        if(i == 1) {
            G[i] = 0;
            B[1] = A[i];
            tail ++;
        }//ここまででtail = 1でBには数字が1つだけ入っている
        
        else{
            if(A[i] == 2){
                B[tail+1] = A[i];
                G[i] = tail;
            }
            else{
                //仮に配列に2が存在しなかったら
                if(B[tail] != 2){
                    B[tail+1] = 4;
                    G[i] = tail;
                }
                else{
                    ll search = tail;
                    while(B[search] == 2 && search > 0){
                        search --;
                    }
                    B[search+1] = A[i];
                    B[tail+1] = 2;
                    G[i] = search;
                }

            }
            tail ++;
        }
        for(ll k = tail; k > 1; k--){
            if(B[k] == B[k-1]){
                B[k-1] += B[k];
                for(ll r = k; r <= tail-1; r++){
                    B[k] = B[k+1];
                }
                tail --; //詰めてないので詰めるのを実装
            }
        }
    }
    for(ll i = 1; i <= N; i++){
        cout << G[i] << endl;
    }
    return 0;
}