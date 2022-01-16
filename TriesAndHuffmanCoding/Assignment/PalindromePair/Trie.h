#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "TrieNode.h"

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, std::string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(std::string word) {
        if (add(root, word)) {
            this->count++;
        }
    }

    bool search(TrieNode *root, std::string word) {
        if (word.empty() == true) {
            return true;
        }

        int index {word[0] - 'a'};
        bool check;

        TrieNode *child;
        if (root->children[index] != nullptr) {
            child = root->children[index];
        }
        else {
            return false;
        }

        check = search(child, word.substr(1));
        return check;
    }

    bool search(std::string word) {
        // Write your code here
        return search(root, word);
    }

    /*..................... Palindrome Pair................... */

    bool isPalindromePair(std::vector<std::string> words) {
        // Write your code here
        for (auto x : words) {
            reverse(x.begin(), x.end());

            while (x.empty() != true) {
                add(x);
                x = x.substr(1);
            }
        }

        bool check;
        for (auto x : words) {
            check = search(x);

            if (check == true) {
                return true;
            }
        }

        return false;
    }
};