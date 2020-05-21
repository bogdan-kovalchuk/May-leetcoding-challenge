#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int countSquares(vector<vector<int>> &matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        int out = 0;
        vector<vector<int>> din(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 1) {
                    din[i + 1][j + 1] = std::min(std::min(din[i][j + 1], din[i + 1][j]), din[i][j]) + 1;
                    out += din[i + 1][j + 1];
                } else {
                    din[i + 1][j + 1] = 0;
                }
            }
        }
        return out;
    }
};

int main() {
    Solution solution = Solution();
    vector<vector<int>> matrix = {{0, 1, 1, 1},
                                  {1, 1, 1, 1},
                                  {0, 1, 1, 1}};

//    vector<vector<int>> matrix = {{1, 0, 1},
//                                  {1, 1, 0},
//                                  {1, 1, 0}};

    std::cout << solution.countSquares(matrix) << std::endl;

    return 0;
}
