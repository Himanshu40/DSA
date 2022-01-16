#include <string>
#include <vector>
#include <iostream>
#include "Trie.h"

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, std::string word) {
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
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(std::string word) {
        if (insertWord(root, word)) {
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

    bool patternMatching(std::vector<std::string> vect, std::string pattern) {
        if (vect.empty() == true) {
            return false;
        }

        for (auto x : vect) {
            while (x.empty() != true) {
                insertWord(x);
                x = x.substr(1);
            }
        }

        return search(pattern);
    }
};
