#include <iostream>
#include <string>
#include "Trie.h"

using namespace std;

int main() {
    // int choice;
    // cin >> choice;
    // Trie t;

    // while (choice != -1) {
    //     string word;
    //     bool ans;
    //     switch (choice) {
    //         case 1:  // insert
    //             cin >> word;
    //             t.insertWord(word);
    //             break;
    //         case 2:  // search
    //             cin >> word;
    //             cout << (t.search(word) ? "true\n" : "false\n");
    //             break;
    //         default:
    //             return 0;
    //     }
    //     cin >> choice;
    // }

    Trie t;

    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");

    cout << t.search("and") << endl;

    t.removeWord("and");
    cout << t.search("and") << endl;

    return 0;
}