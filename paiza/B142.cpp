#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    vector<string> s(N+2);
    string vacant = string(N+2, '*'); //置けないマス
    for(ll i = 0; i <= N+1; i++){
        if(i == 0 || i == N+1) s[i] = vacant;
        else{
            cin >> s[i];
            s[i] = '*' + s[i] + '*'; // 行の両端に置けないマスを追加
        }
    }
    ll cnt = 0;
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= N; j++){
            if(s[i][j] == 'B'){
                // 各方向のチェック関数
                auto checkDirection = [&](ll dx, ll dy) -> bool {
                    ll x = i + dx, y = j + dy;
                    bool foundOpponent = false;
                    while (x >= 1 && x <= N && y >= 1 && y <= N) {
                        if (s[x][y] == 'W') {
                            foundOpponent = true;
                        } else if (s[x][y] == '.' && foundOpponent) {
                            s[x][y] = '*';
                            cnt++;
                            return true;
                        } else {
                            break;
                        }
                        x += dx;
                        y += dy;
                    }
                    return false;
                };

                // 8方向のチェック
                checkDirection(1, 0);  // 右
                checkDirection(-1, 0); // 左
                checkDirection(0, 1);  // 下
                checkDirection(0, -1); // 上
                checkDirection(1, 1);  // 右下
                checkDirection(1, -1); // 右上
                checkDirection(-1, 1); // 左下
                checkDirection(-1, -1); // 左上
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
