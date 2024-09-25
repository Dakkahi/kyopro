#include <iostream>

int flipBits(int num, int pos) {
    // pos番目のビットを反転させるためにマスクを作成
    int mask = 1 << pos;
    return num ^ mask; // XOR演算で指定したビットを反転
}

int main() {
    int num = 29; // 例として 29 (0b11101)
    int pos = 0;  // 2番目のビットを反転
    
    std::cout << "元の数値: " << num << " (" << std::bitset<8>(num) << ")" << std::endl;
    int result = flipBits(num, pos);
    std::cout << "反転後の数値: " << result << " (" << std::bitset<8>(result) << ")" << std::endl;

    return 0;
}
