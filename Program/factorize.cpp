#include <iostream>
#include <vector>

int main() {
    static constexpr int maxN = 100000;

    for (int i = 1; i <= maxN; i++) {
        int x = i;
        std::vector<std::pair<int, int>> P; // {素因数, 割れる回数}
        
        for (int p = 2; (long long)p * p <= x; p++) {
            int cnt = 0;
            while (x % p == 0) {
                cnt++;
                x /= p;
            }
            if (cnt) P.push_back({p, cnt});
        }

        if (x != 1) P.push_back({x, 1});

        std::cout << i << " : ";
        for (auto [p, cnt] : P) std::cout << "{" << p << ", " << cnt << "} ";
        std::cout << '\n';
    }
}