#include <iostream>

using ull = uint64_t;

void print_pow(int k, int maxN) {
    for (int i = 1; i <= maxN; i++) {
        ull x = 1;
        for (int j = 0; j < k; j++) {
            x *= i;
        }
        std::cout << i << "^" << k << "=" << x << '\n';
    }
}

int main() {
    print_pow(2, 100000);
    print_pow(3, 10000);
    print_pow(4, 1000);
    print_pow(5, 300);
    print_pow(6, 200);
    print_pow(7, 100);
    print_pow(8, 50);
}