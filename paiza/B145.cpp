#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;


int main(){
    int N, K;
    cin >> N >> K;
    int b[N*N+1];
    for(int i = 1; i <= N*N; i++) {
        cin >> b[i];
    }

    int c[K+1];
    for(int i = 1; i <= K; i++) cin >> c[i];
    
int flag_v[N+1];
int flag_h[N+1];

int flag_cross[3] = {0,0,0};

for(int i = 1; i <= N; i++){
    flag_v[i] = 0;
    flag_h[i] = 0;
}

for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
        for(int k = 1; k <= K; k++){
            if(b[(i-1)*N + j] == c[k]){
                b[(i-1)*N + j] = 0;
            }
        }
    }
}


for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
            if(b[(i-1)*N + j] == 0){
                flag_v[i] ++;
                flag_h[j] ++;
                if(i == j) flag_cross[1] ++;
                if(i+j == N+1) flag_cross[2] ++;
            }
    }
}


    
    int cnt = 0;
    if(flag_cross[1] == N) cnt ++;
    if(flag_cross[2] == N) cnt ++;
    for(int i = 1; i <= N; i++){
        if(flag_v[i] == N) cnt++;
        if(flag_h[i] == N) cnt ++;
    }

    cout << cnt << endl;
    return 0;

}