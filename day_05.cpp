#include <iostream>
#include <string>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

class Solution {
public:
    int firstUniqChar(const string &s) {
        unordered_map<char, int> map(26);
        for (auto ch : s) ++map[ch];
        for (auto i = 0; i < s.size(); ++i) if (map[s[i]] == 1) return i;
        return -1;
    }
};

int main() {
    Solution solution = Solution();
    string str = "loveleetcode";
    std::cout << solution.firstUniqChar(str) << std::endl;
    return 0;
}
