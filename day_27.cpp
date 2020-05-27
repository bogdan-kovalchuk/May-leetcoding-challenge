#include <vector>
#include <iostream>
#include <numeric>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {

    }
};

int main() {
    int N = 5;
    vector<vector<int>> dislikes = {{1,2},{2,3},{3,4},{4,5},{1,5}};

    Solution solution = Solution();
    std::cout << solution.possibleBipartition(N, dislikes);

    return 0;
}