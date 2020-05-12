#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];
        int l = 0, r = nums.size() - 1, m = 0;

        while (r - l > 2) {
            m = l + (r - l) / 2;
            if (nums[m] == nums[m - 1]) {
                if ((m - l + 1) % 2 == 0) l = m + 1;
                else r = m;
            } else if (nums[m] == nums[m + 1]) {
                if ((r - m + 1) % 2 == 0) r = m - 1;
                else l = m;
            } else return nums[m];
        }
        if (nums[l] == nums[l + 1]) return nums[r];
        else return nums[l];
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7};

    Solution solution = Solution();
    std::cout << solution.singleNonDuplicate(nums) << std::endl;

    return 0;
}
