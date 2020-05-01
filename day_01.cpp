#include <iostream>

bool isBadVersion(int version) {
    return version >= 4;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, m;

        while (l < r) {
            m = l + (r - l) / 2;
            if (!isBadVersion(m)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};

int main() {
    Solution solution = Solution();
    int out = solution.firstBadVersion(5);
    std::cout << out << std::endl;
    return 0;
}
