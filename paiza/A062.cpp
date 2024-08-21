#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    ll N, L;
    cin >> N >> L;

    ll X[N+1][L+1];
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= L; j++) cin >> X[i][j];
    }

    //minimumは[log2{N}]+1のはず
    //L<=8なので2^8だけ試してみるのはアリ

    //各特徴の組み合わせ(2^L-1通り)でどのように識別できるかを逐一調べる


    ll min_param = L;
    for(ll i = 1; i <=(1LL << L); i++){
        //bool flag[L+1];
        ll val[N+1];
        for(ll k = 1; k <= N; k++) val[k] = 0;
        ll cnt = 0;
        //for(ll k = 1; k <= L; k++) flag[k] = false;
        for(ll j = 1; j <= L; j++){
            if((i & (1LL << (j-1))) != 0LL){//ここで，jを2進数で表したときに1となる部分だけの質問をした際の分類を考える
                //flag[j] = true;
                cnt ++;
                for(ll k = 1; k <= N; k++){
                    if(X[k][j] == 1) val[k] += (1LL << (j-1));
                }
            }
        }
        sort(val+1, val+N+1);
        bool flag = true;
        for(ll k = 1; k <= N-1; k++){
            if(val[k] == val[k+1]){
                flag = false;
                break;
            }
        }
        if(flag == true) min_param = min(min_param, cnt);
    }
    cout << min_param << endl;
    return 0;
}