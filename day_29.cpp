#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using std::vector;
using std::unordered_set;
using std::unordered_map;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> visited(numCourses);

        for (const auto &p : prerequisites) graph[p[0]].emplace_back(p[1]);

        for (int i = 0; i < numCourses; ++i)
            if (visited[i] == 0 && !dfs(graph, visited, i)) return false;

        return true;
    }

    bool dfs(const vector<vector<int>> &graph, vector<int> &visited, int v) {
        if (visited[v] == 1) return false;

        visited[v] = 1;

        for (auto u : graph[v]) {
            if (!dfs(graph, visited, u)) return false;
        }

        visited[v] = 2;

        return true;
    }
};

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0},
                                         {0, 1}};

    Solution solution = Solution();
    std::cout << solution.canFinish(numCourses, prerequisites) << std::endl;

    return 0;
}