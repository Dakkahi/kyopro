#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    ll sx, sy;
    cin >> sx >> sy;
    ll df, dr, db, dl;
    cin >> df >> dr >> db >> dl;
    ll N;
    cin >> N;
    char e[N+1];
    char c[N+1];
    for(ll i = 1; i <= N; i++) {
        cin >> e[i] >> c[i];
    }

    char dir[4] = {'F', 'L', 'B', 'R'};
    ll dis[4] = {df, dl, db, dr};

    pair<ll, ll> v = make_pair(0,1);
    pair<ll, ll> r = make_pair(sx, sy);
    pair<ll, ll> v_stack;

    for(ll i = 1; i <= N; i++){
        v_stack = v;
        if(e[i] == 't'){ //ロボットが方向を変えるとき
            for(ll t = 1; t < 4; t++){
                if(dir[t] == c[i]) {
                    v.first = v_stack.first*cos(90*t*M_PI/180) - v_stack.second*sin(90*t*M_PI/180);
                    v.second = v_stack.first*sin(90*t*M_PI/180) + v_stack.second*cos(90*t*M_PI/180);
                }
            }//これでロボットが進む方向の情報を取得
        }
        else{//ロボットが動くとき
            ll idx;
            for(ll t = 0; t < 4; t++){
                if(dir[t] == c[i]) idx = t;
            }
            v_stack.first = v.first*cos(90*idx*M_PI/180) - v.second*sin(90*idx*M_PI/180);
            v_stack.second = v.first*sin(90*idx*M_PI/180) + v.second*cos(90*idx*M_PI/180);

            r.first += dis[idx]*v_stack.first;
            r.second += dis[idx]*v_stack.second;
        }
    }
    cout << r.first << " " << r.second << endl;
    return 0;
}