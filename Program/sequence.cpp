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

void print_binomial(int N) {
    assert(1 <= N && N <= 33);
    using u128 = __uint128_t;

    std::cout << "binomial" << '\n';
    std::vector<u128> fac(N + 1);
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= N; i++) fac[i] = fac[i - 1] * i;

    // 128bit-intを出力
    auto print128 = [](u128 x) {
        static constexpr u128 e15 = 1000000000000000ULL;
        static constexpr u128 e30 = e15 * e15;
        ull C = x / e30;
        x -= C * e30;
        ull B = x / e15;
        x -= B * e15;
        ull A = x;

        bool is_leading = true;
        if (!is_leading || C) {
            is_leading = false;
            std::cout << C;
        }            
        if (!is_leading || B) {
            is_leading = false;
            std::cout << B;
        }
        std::cout << A;
    };

    for (int n = 0; n <= N; n++) {
        for (int r = 0; r <= n; r++) {
            u128 x = fac[n] / (fac[n - r] * fac[r]);
            print128(x);
            std::cout << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

int main() {
    print_factorial(15);
    print_fibonacci(60);
    print_binomial(33);
}