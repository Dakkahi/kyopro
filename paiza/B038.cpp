#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
using namespace std;
using ll = long long;

int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if(c == d) {
        if(a == b*c && b == 2){//このケースのみ一意に定まる
            cout << 1 << " " << 1 << endl;
        }
        else{
            cout << "miss" << endl;
        }
    }

    else{
        ll bunbo = c-d;
        ll bunshi_x = a-d*b;
        ll bunshi_y = b*c-a;

        if(bunshi_x%bunbo != 0 || bunshi_y%bunbo != 0) cout << "miss" << endl;
        else{
            if(bunshi_x/bunbo <= 0 || bunshi_y/bunbo <= 0) cout << "miss" << endl;
            else cout << bunshi_x/bunbo <<" " << bunshi_y/bunbo << endl;
        }
    }
    return 0;
}