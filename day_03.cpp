#include <iostream>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
    bool canConstruct(const string &ransomNote, const string &magazine) {
        unordered_map<char, int> magaz;
        for (const auto &m : magazine) magaz[m]++;
        for (const auto &rn: ransomNote) {
            if (magaz[rn]) magaz[rn]--;
            else return false;
        }
        return true;
    }
};

int main() {
    Solution solution = Solution();
    string ransomNoteJ = "aac";
    string magazine = "aab";
    std::cout << solution.canConstruct(ransomNoteJ, magazine) << std::endl;
    return 0;
}
