#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//連結かどうかを判定するプログラム
int N, M, A[100009], B[100009];
vector<int> G[100009];
bool visited[100009];

void dfs(int pos){
    visited[pos] = true; //i番目のノードを回ったことにする
    for(int i : G[pos]){ //G[i]に含まれている，つまりiとながっているノードを周回する
        if(visited[i] == false) dfs(i);
    }
}

int main(){
    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    dfs(1);

    //連結かどうかの判定
    bool ans = true;
    for(int i = 1; i <= N; i++){
        if(visited[i] == false) ans = false;
    }
    if(ans == false) cout << "The graph is not connected." << endl;
    else cout << "The graph is connected." << endl;
    return 0;
}

