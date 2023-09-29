#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;


long long vector_prod(long long x1,long long x2, long long y1, long long y2){
    return x1*y2 - x2*y1;
}

long long scalar_prod(long long x1,long long x2, long long y1, long long y2){
    return x1*x2 + y1*y2;
}


int main(){
    long long x1,y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    cin >> x4 >> y4;
    string ans = "None";

    long long val1 = vector_prod(x3-x1, x4-x1, y3-y1, y4-y1);
    long long val2 = vector_prod(x3-x2, x4-x2, y3-y2, y4-y2);

    if(val1*val2 < 0) ans = "Yes";
    else if(val1*val2 > 0) ans = "No";
    else{
        if((x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3) || (x1 == x4 && y1 == y4) || (x2 == x4 && y2 == y4)) ans = "Yes"; //点が一致するとき
        else if (scalar_prod(x3-x1, x4-x1, y3-y1, y4-y1)*scalar_prod(x3-x1, x4-x1, y3-y1, y4-y1) == ((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1))*((x4-x1)*(x4-x1) + (y4-y1)*(y4-y1))){ // 平行になったとき
            if(scalar_prod(x3-x1, x4-x1, y3-y1, y4-y1) < 0 || scalar_prod(x3-x2, x4-x2, y3-y2, y4-y2) < 0) ans = "Yes";
            else ans = "No";
        }
        else if (scalar_prod(x3-x2, x4-x2, y3-y2, y4-y2)*scalar_prod(x3-x2, x4-x2, y3-y2, y4-y2) == ((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2))*((x4-x2)*(x4-x2) + (y4-y2)*(y4-y2))){// 平行になったとき
            if(scalar_prod(x3-x1, x4-x1, y3-y1, y4-y1) < 0 || scalar_prod(x3-x2, x4-x2, y3-y2, y4-y2) < 0) ans = "Yes";
            else ans = "No";
        }
        else ans = "No";
    }
    cout << ans << endl;
    return 0;
    
}

// #include <iostream>
// #include <cmath>
// #include <algorithm>
// using namespace std;

// long long vector_prod(long long x1, long long x2, long long y1, long long y2) {
//     return x1 * y2 - x2 * y1;
// }

// long long scalar_prod(long long x1, long long x2, long long y1, long long y2) {
//     return x1 * x2 + y1 * y2;
// }

// int main() {
//     long long x1, y1, x2, y2, x3, y3, x4, y4;
//     cin >> x1 >> y1;
//     cin >> x2 >> y2;
//     cin >> x3 >> y3;
//     cin >> x4 >> y4;
//     string ans = "None";

//     long long val1 = vector_prod(x3 - x1, x4 - x1, y3 - y1, y4 - y1);
//     long long val2 = vector_prod(x3 - x2, x4 - x2, y3 - y2, y4 - y2);

//     if (val1 == 0 && val2 == 0) {
//         // 線分が平行
//         if (max(x1, x2) < min(x3, x4) || max(x3, x4) < min(x1, x2) ||
//             max(y1, y2) < min(y3, y4) || max(y3, y4) < min(y1, y2)) {
//             ans = "No";
//         } else {
//             ans = "Yes";
//         }
//     } else if (val1 * val2 < 0) {
//         ans = "Yes";
//     } else {
//         ans = "No";
//     }

//     cout << ans << endl;
//     return 0;
// }
