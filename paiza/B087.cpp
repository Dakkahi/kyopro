#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    ll h, w, k;
    cin >> h >> w >> k;
    string S[h+1];
    for(ll i = 1; i <= h; i++) cin >> S[i];

    vector<string> A;

    for(ll i = 1; i <= h; i++){
        for(ll j = 0; j < w-k+1; j++){
            string text = "";
            for(ll r = 1; r <= k; r++){
                text += S[i][j+r-1];
            }
            A.push_back(text);
        }
    }

    for(ll j = 0; j < w; j++){
        for(ll i = 1; i <= h-k+1; i++){
            string text = "";
            for(ll r = 1; r <= k; r++){
                text += S[i+r-1][j];
            }
            A.push_back(text);
            //cout << text << endl;
        }
    }

    sort(A.begin(), A.end());

    cout << A[A.size()-1] << endl;
    return 0;
}