#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::pair;

class Solution {
public:
    string frequencySort(const string &s) {
        vector<pair<int ,int>> chars(128, {0,0});

        for(auto ch : s) {
            chars[ch].first = ch;
            chars[ch].second++;
        }

        std::sort(chars.begin(), chars.end(), [](const pair<int ,int> &left, const pair<int ,int> &right){
            return left.second > right.second;
        });

        string out;
        for(auto ch : chars){
            for(int i = 0; i < ch.second; i++){
                out += static_cast<char>(ch.first);
            }
        }
        return out;
    }
};

int main() {
    string s = "tree";

    Solution solution = Solution();
    std::cout << solution.frequencySort(s) << std::endl;

    return 0;
}
