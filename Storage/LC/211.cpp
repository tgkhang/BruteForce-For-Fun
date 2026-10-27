class WordDictionary {
    struct Node {
        Node* child[26];
        bool isEnd;

        Node() : isEnd(false) { fill(child, child + 26, nullptr); }
    };
    Node* root;

    bool dfs(Node* node, const string& s, int index) {
        if (index == s.length())
            // node is not moving to next still in previous state
            return node->isEnd;

        char c = s[index];

        // normal character
        if (c != '.') {
            // can not find word
            if (node->child[c - 'a'] == nullptr)
                return false;
            else  // move next
                return dfs(node->child[c - 'a'], s, index + 1);
        }

        // '.' character
        // test all 26
        for (int i = 0; i < 26; ++i) {
            if (node->child[i] != nullptr) {
                if (dfs(node->child[i], s, index + 1))
                    return true;
            }
        }
        return false;
    }

   public:
    WordDictionary() { root = new Node(); }

    void addWord(string word) {
        Node* cur = root;
        for (char c : word) {
            if (cur->child[c - 'a'] == nullptr)
                cur->child[c - 'a'] = new Node();
            cur = cur->child[c - 'a'];
        }
        cur->isEnd = true;
    }

    bool search(string word) { return dfs(root, word, 0); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */