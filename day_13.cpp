#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>

using std::string;
using std::vector;
using std::deque;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) return "0";
        deque<char> stack;

        int i = 0;
        while (i < num.size()) {
            while (k > 0 && !stack.empty() && num[i] < stack.back()) {
                stack.pop_back();
                k--;
            }
            stack.emplace_back(num[i]);
            i++;
        }


        while (k > 0) {
            stack.pop_back();
            k--;
        }

        while (stack[0] == '0') stack.pop_front();

        if (stack.empty()) return "0";

        string s(stack.begin(), stack.end());

        return s;
    }
};

int main() {
    string num = "112";
    int k = 1;

    Solution solution = Solution();
    std::cout << solution.removeKdigits(num, k) << std::endl;

    return 0;
}
