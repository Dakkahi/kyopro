// you can use includes, for example:
// #include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;

int cross_prod(int x, int y, int X, int Y){
    return x*Y - y*X;
}

vector<int> solution(vector<int> &X, vector<int> &Y) {
    // Implement your solution here
    int siz = X.size();
    vector<pair<int, int>> G;
    for(int i = 0; i < siz; i++) G.push_back(make_pair(X[i], Y[i]));
//外積を考えると，内部にあれば外戚のすべての値の符号が同じ，外部だと一つだけ反転，線上だと0になる

    for(int i = 0; i < siz; i++){
        pair<int, int> a = G[i];
        for(int j = i+1; j < siz; j++){
            pair<int, int> b = G[j];
            for(int k = j+1; k < siz; k++){
                pair<int, int> c = G[k];

                bool flag = true; //判定
                //外積を求めていく
                for(int r = 0; r < siz; r++){
                    pair<int, int> p = G[r];
                    int prod_ab = cross_prod(a.first-p.first, a.second-p.second, b.first-p.first, b.second-p.second);
                    int prod_bc = cross_prod(b.first-p.first, b.second-p.second, c.first-p.first, c.second-p.second);
                    int prod_ca = cross_prod(c.first-p.first, c.second-p.second, a.first-p.first, a.second-p.second);
                    

                    if((prod_ab > 0 && prod_bc > 0 && prod_ca > 0) || (prod_ab < 0 && prod_bc < 0 && prod_ca < 0))
                    {
                        flag = false;
                        break;
                    }

                    if(prod_ab == 0 || prod_bc == 0 || prod_ca == 0){
                        flag = false;
                        break;
                    }
                }
                if(flag == true){
                    vector<int> ans;
                    ans.push_back(i);
                    ans.push_back(j);
                    ans.push_back(k);
                    return ans;
                }
            }
        }
    }
    
}
