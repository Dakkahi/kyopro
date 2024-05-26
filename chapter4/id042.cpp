#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long N;
    long long sum = 1; //1*f(1)は最初から足しておけば良い
    cin >> N;

    //エラトステネスの篩を使って素数をまず抽出し，その後に素数で割り続けてみる
    vector<long long> div(N+1);



    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j += i){
            div[j] ++; //jを約数に持つ数字の配列に+1していく
        }
    }

    long long ans = 0;
    for(int k = 1; k <= N; k++){
        ans += div[k]*k;
    }
    cout << ans << endl;
    return 0;
}