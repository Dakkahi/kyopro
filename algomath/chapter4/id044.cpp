#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M, A[100009], B[100009];
vector<int> G[100009];

int dist[1000009];

//幅優先を使って求める

int main(){
    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    for(int i = 1; i <= N; i++) dist[i] = -1;

    queue<int> Q;
    Q.push(1);
    dist[1] = 0;

    while(!Q.empty()){
        int pos = Q.front();
        Q.pop();
        for(int i : G[pos]){
            if(dist[i] == -1){
                dist[i] = dist[pos] + 1;
                Q.push(i);
            }
        }
    }
    for(int i = 1; i <= N; i++) cout << dist[i] << endl;
    return 0;
}