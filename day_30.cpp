#include <vector>
#include <iostream>
#include <map>
#import <utility>

using std::vector;
using std::map;
using std::pair;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        vector<pair<int, vector<int>>> distances;
        for (auto const &point: points) {
            int distance = point[0] * point[0] + point[1] * point[1];
            distances.emplace_back(pair<int, vector<int>>(distance, point));
        }

        std::sort(distances.begin(), distances.end(), [](pair<int, vector<int>> &left, pair<int, vector<int>> &right) {
            return left.first <= right.first;
        });

        vector<vector<int>> result(K);
        for (int i = 0; i < K; ++i) {
            result[i] = distances[i].second;
        }

        return result;
    }
};

int main() {
    int k = 2;
    vector<vector<int>> points = {{3,  3},
                                  {5,  -1},
                                  {-2, 4}};

    Solution solution = Solution();
    vector<vector<int>> out = solution.kClosest(points, k);

    for (const auto &point : out) {
        std::cout << "{" << point[0] << "," << point[1] << "} ";
    }

    return 0;
}