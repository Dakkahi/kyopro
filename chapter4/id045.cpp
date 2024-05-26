#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int N, M, A[100009], B[100009];
vector<int> G[100009];
bool flag[100009];

int dist[100009];
int main(){
    cin >> N >> M;
    int cnt = 0;
    for(int i = 1; i <= M; i++){
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    for(int i = 1; i <= N; i++) {
        dist[i] = 0;
        flag[i] = false;
    }

    queue<int> Q;
    Q.push(1);
    dist[1] = 0;
    while(!Q.empty()){
        int pos = Q.front();
        Q.pop();
        for(int i : G[pos]){
            if(pos > i) dist[pos]++;
            if(flag[i] == false){
                Q.push(i);
                flag[i] = true;
            }
        }
    }
    for(int i = 1; i <= N; i++){
        if(dist[i] == 1) cnt++;
    }
    cout << cnt << endl;
    return 0;
}