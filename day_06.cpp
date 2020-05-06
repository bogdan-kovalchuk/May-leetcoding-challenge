#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int border = nums.size() / 2;
        unordered_map<int, int> map;
        for (auto n : nums) {
            if (map.find(n) != map.end()) ++map[n];
            else map[n] = 1;
        }

        for (auto m : map) if (m.second > border) return m.first;
        return 0;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> nums = {10, 9, 9, 9, 10};
    std::cout << solution.majorityElement(nums) << std::endl;
    return 0;
}
