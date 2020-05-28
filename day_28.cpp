#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using std::vector;
using std::unordered_set;
using std::unordered_map;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> out;

        for (unsigned int i = 0; i <= num; i++)
            out.emplace_back(Convert(i));

        return out;
    }

    int Convert(unsigned int val) {
        unsigned int mask = 1 << (sizeof(int) * 8 - 1);
        int ones_count = 0;
        for (int i = 0; i < sizeof(int) * 8; i++) {
            if ((val & mask) != 0) ones_count++;
            mask >>= 1;
        }
        return ones_count;
    }
};

int main() {
    int num = 5;

    Solution solution = Solution();
    vector<int> out = solution.countBits(num);

    for (auto n : out){
        std::cout << n << " ";
    }

    return 0;
}