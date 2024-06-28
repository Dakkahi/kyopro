#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;
using ll = long long;

int main(){
    int H, W, N, M;
    cin >> H >> W;
    cin >> N >> M;
    int mask[N+1][M+1];
    for(int i = 1; i <= N; i++){
        string S;
        cin >> S;
        for(int j = 1; j <= M; j++){
            if(S[j-1] != '#') mask[i][j] = 0;
            else mask[i][j] = 1;
        }
    }

    int board[H+1][W+1];
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++) board[i][j] = 0;
    }
    int Q;
    cin >> Q;
    for(int k = 1; k <= Q; k++) {
        int x, y;
        cin >> x >> y;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                board[i+x-1][j+y-1] = (board[i+x-1][j+y-1]+mask[i][j])%2;
            }
        }
    }

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(board[i][j] == 0)cout << '_';
            else cout << '#';

            if(j == W) cout << endl;
        }
    }
    return 0;
}