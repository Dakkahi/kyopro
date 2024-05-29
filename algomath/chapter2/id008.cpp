//全探索
#include<iostream>
using namespace std;

int N, S;
long long ans = 0;

int main(){
    cin >> N >> S;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i+j <= S) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

