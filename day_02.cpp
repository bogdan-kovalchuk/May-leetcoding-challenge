#include <iostream>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
    int numJewelsInStones(const string &J, const string &S) {
        int result = 0;
        unordered_map<char, int> count;

        for (const auto &j : J) count[j] = 0;

        for (const auto &s: S){
            if (count.find(s) != count.end()){
                count[s]++;
            }
        }

        for(const auto &c : count){
            result += c.second;
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    string J = "aA";
    string S = "aAAbbbb";
    int out = solution.numJewelsInStones(J, S);
    std::cout << out << std::endl;
    return 0;
}
