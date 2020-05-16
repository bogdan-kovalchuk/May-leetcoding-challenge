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
        if (head == nullptr || head->next == nullptr) return head;

        int i = 3;
        ListNode *current_odd = head, *first_even = head->next;
        auto current_even = first_even;
        current_odd->next = current_even;

        auto current_node = first_even->next;
        while (current_node != nullptr){
            if (i % 2 == 0){
                current_even->next = current_node;
                current_node = current_node->next;
                current_even = current_even->next;
            } else {
                current_odd->next = current_node;
                current_node = current_node->next;
                current_odd = current_odd->next;
                current_odd->next = first_even;
            }
            i++;
        }
        current_even->next = nullptr;

        return  head;
    }
};

ListNode *createLinkedListFromArray(const vector<int> &list){
    // populate linked list with values
    auto *head = new ListNode();
    head->val = list[0];
    auto current_node = head;
    for (int i = 1; i < list.size(); ++i){
        current_node->next = new ListNode();
        current_node->next->val = list[i];
        current_node = current_node->next;
    }
    return head;
}

void printLinkedList(ListNode *head){
    auto current_node = head;
    while (current_node != nullptr){
        std::cout << current_node->val << " ";
        current_node = current_node->next;
    }
}

int main() {
    Solution solution = Solution();

    vector<int> list = {1, 2, 3, 4, 5};
    auto *head = createLinkedListFromArray(list);

    printLinkedList(solution.oddEvenList(head));

    return 0;
}
