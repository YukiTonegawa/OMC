#include <cassert>
#include <iostream>
#include <vector>

using ull = long long;

void print_fibonacci(int N) {
    assert(1 <= N && N <= 60);
    std::cout << "fibonacci" << '\n';
    ull x = 0, y = 1;
    std::cout << "F_1" << " : " << 0 << '\n';
    if (N == 1) return;
    std::cout << "F_2" << " : " << 1 << '\n';
    
    for (int i = 3; i <= N; i++) {
        ull z = x + y;
        x = y;
        y = z;
        std::cout << "F_" << i << " : " << z << '\n';
    }
    std::cout << '\n';
}

int main() {
    print_fibonacci(60);
}