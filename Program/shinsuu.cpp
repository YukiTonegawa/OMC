#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <vector>

std::string transform(int x, int s) {
    assert(s == 16 || (2 <= s && s <= 9)); // 2~9進か16進
    std::string ans = "";
    while (x) {
        int r = x % s;
        if (r < 10) {
            ans += '0' + r;
        } else {
            ans += 'A' + (r - 10);
        }

        x /= s;
    }
    if (ans.empty()) {
        ans += "0";
    } else {
        std::reverse(ans.begin(), ans.end());
    }
    return ans;
}

int main() {
    static constexpr int maxN = 10000;
    std::vector<int> S{2, 3, 4, 5, 6, 7, 8, 9, 16};
    
    // {進数, 数}
    for (int s : S) {
        for (int i = 0; i <= maxN; i++) {
            std::cout << i << " " << s << " " << transform(i, s) << '\n';
        }
    }

    // {数, 進数}
    for (int i = 0; i <= maxN; i++) {
        for (int s : S) {
            std::cout << i << " " << s << " " << transform(i, s) << '\n';
        }
    }
}