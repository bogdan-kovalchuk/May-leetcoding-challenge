#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int64_t i = 1; i * i <= num; ++i) {
            if ((num % i == 0) && (num / i == i)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int num = 16;
    Solution solution = Solution();
    std::cout << solution.isPerfectSquare(num) << std::endl;
    return 0;
}
