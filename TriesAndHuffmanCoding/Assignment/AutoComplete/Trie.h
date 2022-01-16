#include <iostream>
#include <string>
#include <vector>
#include "TrieNode.h"

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

        if (root->children[index] != NULL) {
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

    TrieNode *search(TrieNode *root, std::string word) {
        if (word.empty() == true) {
            return root;
        }

        int index {word[0] - 'a'};

        TrieNode *child;
        if (root->children[index] != nullptr) {
            child = root->children[index];
        }
        else {
            return nullptr;
        }

        return search(child, word.substr(1));
    }

    TrieNode *search(std::string word) {
        // Write your code here
        return search(root, word);
    }

    int getIndex(TrieNode *root) {
        for (int i {0}; i < 26; ++i) {
            if (root->children[i] != nullptr) {
                return i;
            }
        }

        return -1;
    }

    void allPossibleWords(TrieNode *root, std::string word, std::string output) {
        int index {getIndex(root)};
        
        if (root->isTerminal == true) {
            std::cout << word + output << std::endl;

            if (index == -1) {
                return;
            }
        }

        for (int i {0}; i < 26; ++i) {
            if (root->children[i] != nullptr) {
                allPossibleWords(root->children[i], word, output + root->children[i]->data);
            }
        }
    }

    void autoComplete(std::vector<std::string> input, std::string pattern) {
        // Write your code here
        if (input.empty() == true) {
            return;
        }

        for (auto x : input) {
            insertWord(x);
        }

        TrieNode *check {search(pattern)};

        if (check != nullptr) {
            allPossibleWords(check, pattern, "");

            return;
        }
    }
};
