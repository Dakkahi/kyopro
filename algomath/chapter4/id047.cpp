#include<iostream>
#include<vector>
#include<queue>
using namespace std;

long long N, M, A[200009], B[200009];
vector<long long> G[200009];

long long dist[200009];

//幅優先を使って求める

int main(){
    cin >> N >> M;
    for(long long i = 1; i <= M; i++){
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    for(long long i = 1; i <= N; i++) dist[i] = -1;

    queue<long long> Q;
    
    //連結成分が2個以上でも正しく判定できるようにする
    for(long long r = 1; r <= N; r++){
        if(dist[r] == -1) {
            Q.push(r);
            dist[r] = 0;
        }
        while(!Q.empty()){
            long long pos = Q.front();
            Q.pop();
            for(long long i : G[pos]){
                if(dist[i] == -1){
                    Q.push(i);
                    dist[i] = (dist[pos] + 1)%2; //今回は0と1で色分け
                }
                else if(dist[i] == dist[pos]){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    
    cout << "Yes" << endl;
    return 0;
}