#include <cassert>
#include <iostream>
#include <vector>

using ull = long long;

void print_factorial(int N) {
    assert(1 <= N && N <= 20);
    std::cout << "factorial" << '\n';
    ull x = 1;
    for (int i = 1; i <= N; i++) {
        x *= i;
        std::cout << "F_" << i << " : " << x << '\n';
    }
    std::cout << '\n';
}

int main() {
    print_factorial(15);
}