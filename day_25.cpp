#include <vector>
#include <iostream>
#include <numeric>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    int maxUncrossedLines(const vector<int> &A, const vector<int> &B) {
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));

        for (int i = 1; i <= A.size(); ++i) {
            for (int j = 1; j <= B.size(); ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp.back().back();
    }
};

int main() {
    Solution solution = Solution();

    vector<int> line1 = {1, 4, 2};
    vector<int> line2 = {1, 2, 4};

    std::cout << solution.maxUncrossedLines(line1, line2);

    return 0;
}