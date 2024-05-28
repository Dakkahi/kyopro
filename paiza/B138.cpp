#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<char> s(H*W+4); //i行j列の要素はj+(i-1)*Wとなる．
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++) cin >> s[j+(i-1)*W];
    }
    //ドーナツの穴は内側だけ見れば良いので端は気にしない
    int cnt = 0;
    for(int i = 2; i <= H-1; i++){
        for(int j = 2; j <= W-1; j++){
            if(s[j+(i-1)*W] == '.'){
                //周囲がパンになっているか確認
                if(s[j-1+(i-1-1)*W] == '#' && s[j+(i-1-1)*W] == '#' && s[j+1+(i-1-1)*W] == '#' && s[j-1+(i-1)*W] == '#' && s[j+1+(i-1)*W] == '#' && s[j-1+(i-1+1)*W] == '#' && s[j+(i-1+1)*W] == '#' && s[j+1+(i-1+1)*W] == '#') cnt ++;
                //cout << j+(i-1)*W << endl;
            }
        }
    }
    cout << cnt << endl;
    return 0;

}