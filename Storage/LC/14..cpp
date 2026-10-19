class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int n = strs[0].length();
        for (auto i : strs)
            n = min(n, int(i.length()));

        for (int i = 0; i < n; ++i) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != c)
                    return res;
            }
            res += c;
        }

        return res;
    }
};

class Solution {
    struct Node {
        Node* child[26];
        int cnt;
        bool isEnd;
        Node() : cnt(0), isEnd(false) {
            for (int i = 0; i < 26; ++i)
                child[i] = nullptr;
        }
    };

    Node* root = new Node();

    void insert(const string& s) {
        Node* cur = root;
        for (char c : s) {
            if (cur->child[c - 'a'] == nullptr)
                cur->child[c - 'a'] = new Node();
            cur = cur->child[c - 'a'];
            cur->cnt++;
        }
        cur->isEnd = true;
    }

   public:
    string longestCommonPrefix(vector<string>& strs) {
        for (auto& s : strs)
            insert(s);

        string res;
        Node* cur = root;
        while (true) {
            int only = -1, deg = 0;
            for (int i = 0; i < 26; ++i) {
                if (cur->child[i]) {
                    only = i;
                    ++deg;
                }
            }
            // stop if: 0 or >1 children, or current node ends a word
            if (deg != 1 || cur->isEnd)
                break;
            res += char('a' + only);
            cur = cur->child[only];
        }

        return res;
    }
};