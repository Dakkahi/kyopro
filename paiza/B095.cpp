#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int a[M+1], h[N*M+1];
    for(int i = 1; i <= M; i++) cin >> a[i];

    for(int j = 1; j <= N; j++){
        for(int i = 1; i <= M; i++) cin >> h[(j-1)*M + i];
    }
    int max = 0;
    int score[N+1];
    for(int i  =1; i <= N; i++) score[i] = 100;

    for(int j = 1; j <= N; j++){
        for(int i = 1; i <= M; i++){
            int diff = abs(a[i] - h[(j-1)*M + i]);
            if(5 < diff && diff <= 10) score[j] -= 1;
            if(10 < diff && diff <= 20) score[j] -= 2;
            if(20 < diff && diff <= 30) score[j] -= 3;
            if(diff > 30) score[j] -= 5;
        }
        
        if(max < score[j]) max = score[j];
    }
    cout << max << endl;
    return 0;

}