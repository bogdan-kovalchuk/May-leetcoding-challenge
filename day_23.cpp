#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::pair;

class Solution {
public:
    vector<vector<int>> intervalIntersection(const vector<vector<int>> &A, const vector<vector<int>> &B) {
        vector<vector<int>> out;
        int i = 0, j = 0;

        while (i < A.size() && j < B.size()) {
            int lower = std::max(A[i][0], B[j][0]);
            int upper = std::min(A[i][1], B[j][1]);
            if (lower <= upper) out.emplace_back(vector<int>{lower, upper});
            A[i][1] < B[j][1] ? i++ : j++;
        }
        return out;
    }
};

int main() {
    vector<vector<int>> A = {{0,  2},
                             {5,  10},
                             {13, 23},
                             {24, 25}};
    vector<vector<int>> B = {{1,  5},
                             {8,  12},
                             {15, 24},
                             {25, 26}};

    Solution solution = Solution();
    vector<vector<int>> intersection = solution.intervalIntersection(A, B);

    for(const auto &v: intersection) std::cout << "[" << v[0] << ", " << v[1] << "] ";

    return 0;
}
