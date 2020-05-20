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
    int kthSmallest(TreeNode *root, int k) {

    }
};

TreeNode *insertLevelOrder(vector<int> nodes, TreeNode *root, int i, int n) {
    // Base case for recursion
    if (i < n && nodes[i] != 0) {
        auto *temp = new TreeNode(nodes[i]);
        root = temp;

        // insert left child
        root->left = insertLevelOrder(nodes, root->left, 2 * i + 1, n);

        // insert right child
        root->right = insertLevelOrder(nodes, root->right, 2 * i + 2, n);
    }
    return root;
}

int main() {
    int k = 3;
    vector<int> nodes = {5, 3, 6, 2, 4, 0, 0, 1};
    Solution solution = Solution();

    TreeNode *root = insertLevelOrder(nodes, root, 0, nodes.size());

    std::cout << solution.kthSmallest(root, k) << std::endl;

    return 0;
}
