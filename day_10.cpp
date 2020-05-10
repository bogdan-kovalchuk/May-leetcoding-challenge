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

    }
};

int main() {
    int N = 4;
    vector<vector<int>> trust = {{1, 3},
                                 {1, 4},
                                 {2, 3},
                                 {2, 4},
                                 {4, 3}};

    Solution solution = Solution();
    std::cout << solution.findJudge(N, trust) << std::endl;

    return 0;
}
