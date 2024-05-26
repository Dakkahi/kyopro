#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 各頂点への到達距離をdistに格納
int R, C, sy, sx, gy, gx;
char A[54][54];
int dist[2504];
vector<int> G[2504]; // i行j列のノードはC*(i-1) + jとなる

int main() {
    cin >> R >> C;
    cin >> sy >> sx;
    cin >> gy >> gx;

    // グラフの初期化
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            dist[C*(i-1) + j] = -1;
            cin >> A[i][j];
        }
    }

    // グラフの作成
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (A[i][j] != '#') {
                int node = C*(i-1) + j;
                if (i > 1 && A[i-1][j] != '#') {
                    G[node].push_back(C*(i-2) + j);
                    G[C*(i-2) + j].push_back(node);
                }
                if (i < R && A[i+1][j] != '#') {
                    G[node].push_back(C*i + j);
                    G[C*i + j].push_back(node);
                }
                if (j > 1 && A[i][j-1] != '#') {
                    G[node].push_back(C*(i-1) + j - 1);
                    G[C*(i-1) + j - 1].push_back(node);
                }
                if (j < C && A[i][j+1] != '#') {
                    G[node].push_back(C*(i-1) + j + 1);
                    G[C*(i-1) + j + 1].push_back(node);
                }
            }
        }
    }

    // 幅優先探索 (BFS)
    queue<int> Q;
    Q.push(C*(sy-1) + sx);
    dist[C*(sy-1) + sx] = 0;
    while (!Q.empty()) {
        int pos = Q.front();
        Q.pop();
        
        for (int i : G[pos]) {
            if (dist[i] == -1) {
                Q.push(i);
                dist[i] = dist[pos] + 1;
            }
        }
    }

    cout << dist[C*(gy-1) + gx] << endl;
    return 0;
}
