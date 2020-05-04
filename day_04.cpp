#include <iostream>
#include <string>
#include <unordered_map>
#include <bitset>

using std::string;
using std::bitset;
using std::unordered_map;

class Solution {
public:
    int findComplement(int num) {
        string binary = bitset<32>(num).to_string();
        binary.erase(0, binary.find_first_not_of('0'));
        for (auto &x : binary) {
            if (x == '0') x = '1';
            else x = '0';
        }
        return std::bitset<32>(binary).to_ulong();
    }
};

int main() {
    Solution solution = Solution();
    int num = 5;
    std::cout << solution.findComplement(num) << std::endl;
    return 0;
}
