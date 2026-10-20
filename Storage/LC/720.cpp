class Solution {
    struct Node {
        Node* child[26];
        bool isEnd = false;
        Node() : isEnd(false) {
            for (int i = 0; i < 26; ++i)
                child[i] = nullptr;
        }
    };

    Node* root = new Node();

    void insert(const string& s) {
        Node* cur = root;
        for (char c : s) {
            if (!cur->child[c - 'a'])
                cur->child[c - 'a'] = new Node();

            cur = cur->child[c - 'a'];
        }
        cur->isEnd = true;
    }
    bool buildable(const string& w) {
        Node* cur = root;
        for (int k = 0; k < (int)w.size(); ++k) {
            cur = cur->child[w[k] - 'a'];

            if (k < w.size() - 1 && !cur->isEnd)
                return false;
        }
        return true;
    }

   public:
    string longestWord(vector<string>& words) {
        for (string& s : words)
            insert(s);

        sort(words.begin(), words.end());
        string res = "";
        for (auto& s : words) {
            if (buildable(s) && s.size() > res.size())
                res = s;
        }

        return res;
    }
};



// c2
class Solution {
   public:
    string longestWord(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());

        string res = "";
        sort(words.begin(), words.end());

        for (const string& s : words) {
            bool tmp = true;

            for (int i = 1; i < s.length(); ++i) {
                if (!dict.count(s.substr(0, i))) {
                    tmp = false;
                    break;
                }
            }

            if (tmp && s.length() > res.length())
                res = s;
        }

        return res;
    }
};