#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int dist[N+4];
    for(int i = 1; i <= N; i++) dist[i] = 0;
    int x[M+9], y[M+9]; //xが勝ち，yが負け
    for(int i = 1; i <= M; i++) cin >> x[i] >> y[i];
    
    //後ろにいる人数をdistに記録
    for(int i = 1; i <= M; i++){
        dist[x[i]] += dist[y[i]] + 1;
    }
    int max = 0;
    for(int i = 1; i <= N; i++){
        if(max < dist[i]) max = dist[i];
    }

    for(int i = 1; i <= N; i++){
        if(max == dist[i]) cout << i << endl;
    }

    return 0;
}