#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
using namespace std;

int main(){
    int x, y, k, N;
    cin >> x >> y;
    cin >> k;
    cin >> N;

    int X[N+4], Y[N+4], P[N+4];
    int dist[N+4];
    int min = 1000*1000 + 1;
    int index[k+1];

    for(int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i] >> P[i];
        dist[i] = (x - X[i])*(x-X[i]) + (y - Y[i])*(y - Y[i]);
    }
    int j = 1;
    while(j <= k){
        for(int r = 1; r <= N; r++){
            if(dist[r] < min){
                min = dist[r];
                index[j] = r;
            }
        }
        dist[index[j]] = 1000*1000 + 100;
        min = 1000*1000 + 1;
        j ++;
    }
    double ave = 0;
    for(int s = 1; s <= k; s++){
        ave += P[index[s]];
    }
    ave = std::round(ave/k);
    cout << ave << endl;
    return 0;
}