#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        fillCell(image, sr, sc, image[sr][sc], newColor);
        return image;
    }

    void fillCell(vector<vector<int>> &image, int sr, int sc, int color, int newColor) {
        if (sr < 0 ||
            sr == image.size() ||
            sc < 0 ||
            sc == image[0].size() ||
            image[sr][sc] != color ||
            image[sr][sc] == newColor)
            return;

        image[sr][sc] = newColor;
        fillCell(image, sr + 1, sc, color, newColor);
        fillCell(image, sr - 1, sc, color, newColor);
        fillCell(image, sr, sc + 1, color, newColor);
        fillCell(image, sr, sc - 1, color, newColor);
    }
};

int main() {
//    int sr = 1, sc = 1, newColor = 2;
//    vector<vector<int>> image = {{1, 1, 1},
//                                 {1, 1, 0},
//                                 {1, 0, 1}};

    int sr = 1, sc = 1, newColor = 1;
    vector<vector<int>> image = {{0, 0, 0},
                                 {0, 1, 1}};

    Solution solution = Solution();
    vector<vector<int>> out = solution.floodFill(image, sr, sc, newColor);

    for (int i = 0; i < out.size(); ++i) {
        for (int j = 0; j < out[0].size(); ++j) {
            std::cout << image[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
