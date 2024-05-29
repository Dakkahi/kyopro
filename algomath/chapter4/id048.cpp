#include <iostream>
#include <vector>
#include<math.h>
#include<algorithm>
#include <queue>
using namespace std;
int main(){
    int K;
    cin>>K;
    vector<int> dist(K,K);
    queue <int>q;
    dist[1]=1;
    q.push(1);
    while(!q.empty())
    {
        int w=q.front();
        q.pop();
        int n=(w*10)%K;
        if(dist[n]>dist[w])
        {
            dist[n]=dist[w];
            q.push(n);
        }
        n=(w+1)%K;
        if(dist[n]>dist[w])
        {
            dist[n]=dist[w]+1;
            q.push(n);
        }
    }
    cout<<dist[0]<<endl;
    return 0;
    
}