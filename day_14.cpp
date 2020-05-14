#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>

using std::string;
using std::vector;
using std::deque;

class Trie {
    Trie* node[26];
    bool endOfTheWord = false;
public:
    /** Initialize data structure. */
    Trie() {
        for(auto &n : node) n = nullptr;
        endOfTheWord = false;
    }

    /** Inserts a word into the trie. */
    void insert(const string &word) {
        Trie* curr = this;
        for(const auto &ch : word){
            if (!curr->node[ch - 'a']){
                curr->node[ch - 'a'] = new Trie();
            }
            curr = curr->node[ch - 'a'];
        }
        curr->endOfTheWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(const string &word) {
        Trie* curr = this;
        for(const auto &ch : word){
            if (curr->node[ch - 'a']) curr = curr->node[ch - 'a'];
            else return false;
        }
         return curr->endOfTheWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string &prefix) {
        Trie* curr = this;
        for(const auto &ch : prefix){
            if (curr->node[ch - 'a']) curr = curr->node[ch - 'a'];
            else return false;
        }
        return true;
    }
};

int main() {
    Trie *trie = new Trie();

    trie->insert("apple");
    std::cout << trie->search("apple") << std::endl;   // returns true
    std::cout << trie->search("app") << std::endl;     // returns false
    std::cout << trie->startsWith("app") << std::endl; // returns true
    trie->insert("app");
    std::cout << trie->search("app") << std::endl;     // returns true

    return 0;
}
