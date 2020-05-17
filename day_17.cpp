#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    vector<int> findAnagrams(const string &s, string p) {
        if (s.size() < p.size()) return {};

        vector<int> out;
        int chars[26] = {0};

        for(int j = 0; j < p.size(); j++){
            chars[s[j] - 'a']++;
            chars[p[j] - 'a']--;
        }
        if (checkAnagram(chars)) out.emplace_back(0);

        for(int i = 1; i <= s.size() - p.size(); ++i){
            chars[s[i - 1] - 'a']--;
            chars[s[i - 1 + p.size()] - 'a']++;
            if (checkAnagram(chars)) out.emplace_back(i);
        }
        return out;
    }

    bool checkAnagram(const int chars[26]){
        bool anagrams = true;
        for(int i = 0; i < 26; ++i){
            if (chars[i] != 0) {
                anagrams = false;
                break;
            }
        }
        return anagrams;
    }
};

int main() {
    string s = "baa";
    string p = "aa";

    Solution solution = Solution();
    auto out =  solution.findAnagrams(s, p);

    for(auto n : out){
        std::cout << n << " ";
    }

    return 0;
}
