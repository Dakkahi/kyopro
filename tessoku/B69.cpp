#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int N,M;
string C;

struct edge{
    int to,cap,rev;
};

class MaximumFlow{
    public:
    vector<edge>G[100009];
    bool used[100009];
    int siz;

    void init(int N){
        siz=N;
        for(int i=0;i<=siz;i++)G[i].clear();
    }

    void add_edge(int A,int B,int C){
        int sizeA=G[A].size();
        int sizeB=G[B].size();

        G[A].push_back({B,C,sizeB});
        G[B].push_back({A,0,sizeA});
    }

    int DFS(int g,int v,int f){
        used[v]=true;
        if(v==g)return f;

        for(int i=0;i<G[v].size();i++){
            if(used[G[v][i].to])continue;
            if(G[v][i].cap==0)continue;

            int flow=DFS(g,G[v][i].to,min(G[v][i].cap,f));

            if(flow>=1){
                G[v][i].cap-=flow;
                G[G[v][i].to][G[v][i].rev].cap+=flow;
                return flow;
            }
        }

        return 0;
    }

    int max_flow(int s,int t){
        int maxflow=0;
        while(true){
            for(int i=0;i<=siz;i++)used[i]=false;

            int flow=DFS(t,s,1000000000);

            if(flow==0)break;

            maxflow+=flow;
        }

        return maxflow;
    }
};

int main(){
    cin>>N>>M;
    MaximumFlow MF;
    MF.init(N+25);

    for(int i=1;i<=N;i++)MF.add_edge(0,i,10);
    for(int i=1;i<=24;i++)MF.add_edge(i+N,N+25,M);
    

    for(int i=1;i<=N;i++){
        cin>>C;
        for(int j=1;j<=24;j++){
            if(C[j-1]=='1')MF.add_edge(i,j+N,1);
        }
    }

    if(MF.max_flow(0,N+25)==M*24)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}