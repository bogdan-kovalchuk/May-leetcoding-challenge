#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    bool checkInclusion(const string &s1, const string &s2) {
        if(s1.size() > s2.size() || s2.empty()) return false;

        vector<int> s1v(26, 0), s2v(26, 0);

        for(int i = 0; i < s1.size(); ++i) {
            ++s1v[s1[i] - 'a'];
            ++s2v[s2[i] - 'a'];
        }

        if (s1v == s2v) return true;

        for(int i = s1.size(); i < s2.size(); ++i){
            ++s2v[s2[i] - 'a'];
            --s2v[s2[i - s1.size()] - 'a'];
            if(s1v == s2v) return true;
        }
        return false;
    }
};

int main() {
    string s1 = "ab";
    string s2 = "a";

    Solution solution = Solution();
    std::cout <<  solution.checkInclusion(s1, s2) << std::endl;

    return 0;
}
