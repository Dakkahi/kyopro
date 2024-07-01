#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

struct pos{
    ll num;
    char dir;
};

struct Edge
{
	ll to;

	double cost;
};

int main(){
    ll N;
    cin >> N;
    pos start, end;
    cin >> start.num >> start.dir;
    cin >> end.num >> end.dir;
    double dist = 1LL << 60;

    vector<vector<Edge>> G;
    priority_queue<Edge, greater<int>> Q;

    for(ll i = 0; i <= 4*N; i++){ 
        if(i == 0){
            for(ll j = 1; j <= 4; j++){
                Edge e;
                e.to = j;
                e.cost = 100.0;
                G[i].push_back(e);
            }
        }else{
            for(ll j = 1; j <= 4; j++){
                Edge e;
                
            }
        }
    }

}