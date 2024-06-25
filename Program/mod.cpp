#include <iostream>

// pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
std::pair<long long, long long> inv_gcd(long long a, long long b) {
    if (a == 0) return {b, 0};
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;
    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;
        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

bool is_pow2(int x) {
    return __builtin_popcount(x) == 1;
}

int main() {
    static constexpr bool prime_only_mode = false;
    static constexpr bool pow2_only_mode = true;
    static constexpr int maxM = 512;

    for (int m = 1; m <= maxM; m++) {
        if (prime_only_mode && !is_prime(m)) continue;
        if (pow2_only_mode && !is_pow2(m)) continue;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                std::cout << "mod" << m << " " << i << "+" << j << "≡" << (i + j) % m << '\n';
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                std::cout << "mod" << m << " " << i << "-" << j << "≡" << (i - j + m) % m << '\n';
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                std::cout << "mod" << m << " " << i << "*" << j << "≡" << (i * j) % m << '\n';
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                auto [g, x] = inv_gcd(j, m);
                if (j == 0 || g != 1) {
                    std::cout << "mod" << m << " " << i << "/" << j << "≡" << "-1" << '\n';
                } else {
                    std::cout << "mod" << m << " " << i << "/" << j << "≡" << (i * x) % m << '\n';
                }
            }
        }
        for (int i = 0; i < m; i++) {
            int x = 1;
            for (int j = 0; j < m; j++, x = (x * i) % m) {
                std::cout << "mod" << m << " " << i << "^" << j << "≡" << x << '\n';
            }
        }
        std::cout << '\n';
    }
}