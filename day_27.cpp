#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using std::vector;
using std::unordered_set;
using std::unordered_map;

class Solution {
public:
    vector<unordered_set<int>> graph;
    unordered_map<int, int> color;
public:
    bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
        graph.resize(N + 1);
        for (const auto &dislike : dislikes) {
            graph[dislike[0]].insert(dislike[1]);
            graph[dislike[1]].insert(dislike[0]);
        }
        for (int node = 1; node <= N; ++node)
            if (color.find(node) == color.end() && !dfs(node, 0))
                return false;
        return true;
    }

    bool dfs(int node, int c) {
        if (color.find(node) != color.end())
            return color[node] == c;
        color[node] = c;

        for (int nei: graph[node])
            if (!dfs(nei, c ^ 1))
                return false;
        return true;
    }
};

int main() {
    int N = 10;
    vector<vector<int>> dislikes = {
            {{4, 7}, {4, 8}, {5, 6}, {1, 6}, {3, 7}, {2, 5}, {5, 8}, {1, 2}, {4, 9}, {6, 10}, {8, 10}, {3, 6}, {2, 10}, {9, 10}, {3, 9}, {2, 3}, {1, 9}, {4, 6}, {5, 7}, {3, 8}, {1, 8}, {1, 7}, {2, 4}}};

    Solution solution = Solution();
    std::cout << solution.possibleBipartition(N, dislikes);

    return 0;
}