class Trie {
   private:
    struct Node {
        bool isEnd;
        Node* child[26];

        Node() : isEnd(false) { fill(child, child + 26, nullptr); }
    };

    Node* root;

   public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* cur = root;

        for (char c : word) {
            if (cur->child[c - 'a'] == nullptr)
                cur->child[c - 'a'] = new Node();
            cur = cur->child[c - 'a'];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        Node* cur = root;

        for (char c : word) {
            if (cur->child[c - 'a'] == nullptr)
                return false;
            cur = cur->child[c - 'a'];
        }
        return cur->isEnd;
    }

    bool startsWith(string word) {
        Node* cur = root;

        for (char c : word) {
            if (cur->child[c - 'a'] == nullptr)
                return false;
            cur = cur->child[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */