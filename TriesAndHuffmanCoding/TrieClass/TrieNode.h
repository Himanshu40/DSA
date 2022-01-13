class TrieNode {
    public:
        char data;
        TrieNode **children;
        bool isTerminal;

        TrieNode(char data)
            : data {data}, isTerminal {false}, children {new TrieNode*[26]} {
                for (int i {0}; i < 26; ++i) {
                    children[i] = nullptr;
                }
            }
};