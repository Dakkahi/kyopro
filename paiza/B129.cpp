#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
using namespace std;

int main(){
    int n, m, h, w;
    cin >> n >> m;
    cin >> h >> w;

    int a[n+1], b[n+1], c[n+1], d[n+1], e[n+1];
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];

    int field[h*w+1]; //i行j列は(i-1)*w + j
    int r[m+1];
    for(int i = 1; i <= h*w; i++) {
        field[i] = 0;
        
    }
    for(int i = 1; i <= m; i++){
        r[i] =0;
    }

    for(int k = 1; k <= n; k++){ //おとなしく全部の情報を入れる
        for(int i = a[k]; i <= b[k]; i++){
            for(int j = c[k]; j <= d[k]; j++){
                if(field[(i-1)*w + j] == 0){
                    field[(i-1)*w + j] = e[k];
                }
                else{
                    r[field[(i-1)*w + j]] += 1;
                    field[(i-1)*w + j] = e[k];
                }
            }
        }
    }
    for(int j = 1; j <= m; j++) cout << r[j] << endl;
    for(int i = 1; i <= h*w; i++){
        if(field[i] == 0) {
            if(i%w != 0) cout << ".";
            else cout << "." << endl;
        }
        else{
            if(i%w == 0){
                cout << field[i] << endl;
            }
            else{
                cout << field[i];
            }
        }
    }
    return 0;
}