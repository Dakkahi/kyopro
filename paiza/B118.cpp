#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;

    vector<pair<pair<string, ll>, ll>> v(N);

    for(ll i = 0; i < N; i++){
        string name;
        ll len;
        ll birth;
        cin >> name >> len >> birth;
        v[i] = make_pair(make_pair(name, birth), len);
    }
    sort(v.begin(), v.end(), [](const pair<pair<string, ll>, ll>& a, const pair<pair<string, ll>, ll>& b) {
        if (a.second != b.second) {
            return a.second < b.second;
        } else if (a.first.second != b.first.second) {
            return a.first.second > b.first.second;
        } else {
            return a.first.first < b.first.first;
        }
    });

    for(ll i = 0; i < N; i++){
        cout << v[i].first.first << endl;
    }
    return 0;
}