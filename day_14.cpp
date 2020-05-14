#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>

using std::string;
using std::vector;
using std::deque;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {

    }

    /** Returns if the word is in the trie. */
    bool search(string word) {

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {

    }
};

int main() {
    Trie *trie = new Trie();

    trie->insert("apple");
    trie->search("apple");   // returns true
    trie->search("app");     // returns false
    trie->startsWith("app"); // returns true
    trie->insert("app");
    trie->search("app");     // returns true

    return 0;
}
