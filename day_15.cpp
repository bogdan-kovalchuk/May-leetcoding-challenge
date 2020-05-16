#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int maxSubarraySumCircular(vector<int> &A) {
        int sum, max_end, min_end;
        int max_sum = INT_MIN;
        int min_sum = INT_MAX;
        sum = max_end = min_end = 0;
        for (auto num : A) {
            sum += num;
            max_end = std::max(max_end + num, num);
            max_sum = std::max(max_end, max_sum);
            min_end = std::min(min_end + num, num);
            min_sum = std::min(min_end, min_sum);
        }
        if (max_sum > 0) return std::max(max_sum, sum - min_sum);
        return max_sum;
    }
};

int main() {
    vector<int> num = {5, -3, 5};

    Solution solution = Solution();
    std::cout << solution.maxSubarraySumCircular(num) << std::endl;

    return 0;
}
