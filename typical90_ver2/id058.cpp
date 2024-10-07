#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

// 各桁の和を計算する関数
ll sum_of_digits(ll num) {
    ll sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main(){
    ll N, K;
    cin >> N >> K;

    bool isemerge[100000] = {false};  // Nの出現を記録する
    vector<ll> val;  // 各ステップでのNの値を保存
    vector<ll> first_occurrence(100000, -1);  // Nの最初の出現位置を記録

    ll s = 0;  // サイクルの長さ
    ll cycle_start = -1;  // サイクルの開始位置
    for(ll i = 0; i < 100000; i++){  // 最大10万回ループ
        if(isemerge[N] == false){  // Nがまだ出現していない場合
            val.push_back(N);  // Nを保存
            isemerge[N] = true;  // Nの出現を記録
            first_occurrence[N] = i;  // Nの最初の出現位置を記録
            s = i + 1;  // サイクルの長さを記録

            // Nを次の値に更新
            N += sum_of_digits(N);  // 各桁の和をNに加える
            N %= 100000;  // Nを10万未満に制限
        } else {
            cycle_start = first_occurrence[N];  // サイクルの開始位置を記録
            break;  // サイクルが見つかったらループを抜ける
        }
    }

    if (K < cycle_start) {
        // サイクルが始まる前の値を出力
        cout << val[K] << endl;
    } else {
        // サイクルが始まった後のKに対する値を出力
        ll cycle_length = s - cycle_start;  // サイクルの長さ
        ll idx = (K - cycle_start) % cycle_length + cycle_start;  // サイクル内のインデックスを計算
        cout << val[idx] << endl;
    }

    return 0;
}
