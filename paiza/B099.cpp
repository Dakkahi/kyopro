#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int p[N*M+1];
    for(int i = 1; i<= N*N; i++) cin >> p[i]; //n行m列は(m - 1)*N + n

    int flag[N+1]; //flagが1以上のところは通れない
    for(int j = 1; j <= N; j++) flag[j] = 0;

    int min = N*N;
    for(int j = 1; j <= N; j++){
        for(int i = 1; i <= N; i++){
            if(p[(i-1)*N + j] >= M) flag[j] += 1;
        }
        if(min > flag[j]) min = flag[j];
    }
    if(min > 0){
        cout << "wait" << endl;
        return 0;
    }
    else{
        int first = 0;
        for(int i = 1; i <= N; i++){
            if(flag[i] == 0 && first != 0) cout << " " << i;
            if(flag[i] == 0 && first == 0){
                first += 1;
                cout << i;
            }
        }
    }

    return 0;
}