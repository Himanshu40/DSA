#include <string>
#include "TrieNode.h"

class Trie {
        TrieNode *root;

        void insertWord(TrieNode *root, std::string word) {
            if (word.empty() == true) {
                root->isTerminal = true;

                return;
            }

            int index {word[0] - 'a'};

            TrieNode *child;
            if (root->children[index] != nullptr) {
                child = root->children[index];
            }
            else {
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            insertWord(child, word.substr(1));
        }

        bool search(TrieNode *root, std::string word) {
            if (word.empty() == true) {
                if (root->isTerminal == true) {
                    return true;
                }

                return false;
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

        void removeWord(TrieNode *root, std::string word) {
            if (word.empty() == true) {
                root->isTerminal = false;

                return;
            }

            int index {word[0] - 'a'};
            TrieNode *child;

            if (root->children[index] != nullptr) {
                child = root->children[index];
            }
            else {
                return;
            }

            removeWord(child, word.substr(1));

            if (child->isTerminal == false) {
                for (int i {0}; i < 26; ++i) {
                    if (child->children[i] != nullptr) {
                        return;
                    }
                }

                delete child;
                root->children[index] = nullptr;
            }
        }
    public:
        Trie()
            : root {new TrieNode('\0')} {}

        void insertWord(std::string word) {
            insertWord(root, word);
        }

        bool search(std::string word) {
            return search(root, word);
        }

        void removeWord(std::string word) {
            removeWord(root, word);
        }
};