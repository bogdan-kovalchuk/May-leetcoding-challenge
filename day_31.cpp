#include <vector>
#include <iostream>
#include <map>
#include <string>

using std::vector;
using std::map;
using std::string;

class Solution {
public:
    int minDistance(const string &word1, const string &word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        for (int i = 0; i <= word1.size(); ++i) dp[i][0] = i;
        for (int i = 0; i <= word2.size(); ++i) dp[0][i] = i;

        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + std::min(std::min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                }
            }
        }
        return dp.back().back();
    }
};

int main() {
    string word1 = "intention", word2 = "execution";

    Solution solution = Solution();
    std::cout << solution.minDistance(word1, word2) << std::endl;

    return 0;
}