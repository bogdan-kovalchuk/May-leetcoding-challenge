#include <vector>
#include <iostream>
#include <numeric>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        unordered_map<int, int> num_map;
        int sum = 0, max_sub_arr = 0;
        num_map[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 1 ? 1 : -1);
            if (num_map.find(sum) != num_map.end()) {
                max_sub_arr = std::max(max_sub_arr, i - num_map[sum]);
            } else {
                num_map[sum] = i;
            }
        }
        return max_sub_arr;
    }
};

int main() {
    Solution solution = Solution();

    vector<int> nums = {1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1};

    std::cout << solution.findMaxLength(nums);

    return 0;
}