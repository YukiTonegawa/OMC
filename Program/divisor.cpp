#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    static constexpr int maxN = 100000;

    for (int i = 1; i <= maxN; i++) {
        int x = i;
        std::vector<int> D; // 約数
        
        for (int d = 1; (long long)d * d <= x; d++) {
            if (x % d) continue;
            D.push_back(d);
            if ((long long)d * d != x) D.push_back(x / d);
        }

        std::sort(D.begin(), D.end());

        std::cout << i << " : ";
        for (auto d : D) std::cout << d << " ";
        std::cout << '\n';
    }
}