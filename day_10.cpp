#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

class Solution {
public:
    int findJudge(int N, vector<vector<int>> &trust) {
        vector<int> for_whom_voted_count(N + 1, 0);
        vector<int> who_voted_count(N + 1, 0);

        for (const auto &t : trust) {
            for_whom_voted_count[t[1]]++;
            who_voted_count[t[0]]++;
        }
        for (int i = 1; i <= N; ++i) {
            if ((for_whom_voted_count[i] == N - 1) &&
                (who_voted_count[i] == 0)) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    int N = 3;
    vector<vector<int>> trust = {{1, 3},
                                 {2, 3},
                                 {3, 1}};

    Solution solution = Solution();
    std::cout << solution.findJudge(N, trust) << std::endl;

    return 0;
}
