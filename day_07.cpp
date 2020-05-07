#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>

using std::string;
using std::vector;
using std::unordered_map;
using std::queue;
using std::pair;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isCousins(TreeNode *root, int x, int y) {
        vector<TreeNode *> queue = {root};
        while (!queue.empty()) {
            vector<TreeNode *> level_queue;
            vector<TreeNode *> nodes;
            for (auto elem : queue) {
                if (elem->left) {
                    if (elem->left->val == x || elem->left->val == y) nodes.emplace_back(elem);
                    level_queue.emplace_back(elem->left);
                }
                if (elem->right) {
                    if (elem->right->val == x || elem->right->val == y) nodes.emplace_back(elem);
                    level_queue.emplace_back(elem->right);
                }
            }
            if (nodes.size() > 1) {
                if (nodes[0] != nodes[1]) return true;
                else return false;
            }
            queue = level_queue;
        }
        return false;
    }
};

int main() {
    Solution solution = Solution();
    int x = 5;
    int y = 4;
    auto *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    std::cout << solution.isCousins(root, x, y) << std::endl;
    return 0;
}
