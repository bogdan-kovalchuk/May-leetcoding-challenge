#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>> &coords) {
        if (coords.size() == 2) return true;
        if ((coords[0][0] - coords[1][0]) == 0) return false;

        // line: y = a * x + b
        int a = (coords[0][1] - coords[1][1]) / (coords[0][0] - coords[1][0]);
        int b = coords[0][1] - a * coords[0][0];

        for (int i = 2; i < coords.size(); ++i) {
            int y = a * coords[i][0] + b;
            if (y != coords[i][1]) return false;
        }
        return true;
    }
};

int main() {
    vector<vector<int>> coordinates = {{1, 2},
                                       {2, 3},
                                       {3, 4},
                                       {4, 5},
                                       {5, 6},
                                       {6, 7}};

    Solution solution = Solution();

    std::cout << solution.checkStraightLine(coordinates) << std::endl;
    return 0;
}
