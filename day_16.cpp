#include <iostream>
#include <vector>

using std::string;
using std::vector;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {

    }
};

int main() {
    vector<int> num = {5, -3, 5};

    Solution solution = Solution();
    std::cout << solution.maxSubarraySumCircular(num) << std::endl;

    return 0;
}
