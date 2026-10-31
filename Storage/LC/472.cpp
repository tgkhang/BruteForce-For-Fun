class Solution {
    struct Node {
        Node* child[26];
        bool isEnd;
        Node() : isEnd(false) { fill(child, child + 26, nullptr); }
    };

    Node* root = new Node();

    void insert(const string& s) {
        Node* cur = root;
        for (char c : s) {
            int t = c - 'a';
            if (cur->child[t] == nullptr)
                cur->child[t] = new Node();
            cur = cur->child[t];
        }
        cur->isEnd = true;
    }

    bool checkdfs(const string& word, int start, int count, vector<int>& memo) {
        Node* cur = root;

        // go to the end of the word, if that word created for more than 2b
        // return true
        if (start == word.length())  // end
            return count >= 2;

        if (memo[start] !=
            -1)  // can be cut (1), can not be cut (0) vd: sdogcat in catsdogcat
            return memo[start] == 1;

        for (int i = start; i < word.length(); ++i) {
            int t = word[i] - 'a';
            if (cur->child[t] == nullptr)  // can not find word return right here
                break;                     // return memo[start] = 0;
            cur = cur->child[t];

            if (cur->isEnd)
                if (checkdfs(word, i + 1, count + 1, memo))
                    return memo[start] = 1;
        }
        return memo[start] = 0;
    }

   public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (const string& s : words)
            insert(s);

        vector<string> res;
        for (const string& s : words) {
            vector<int> dp(s.length(),
                           -1);  // -1 not visited, 1: true, 0: can not cut here
            if (checkdfs(s, 0, 0, dp))
                res.push_back(s);
        }
        return res;
    }
};


// c2
class Solution {
    unordered_set<string> dict;
    unordered_map<string, bool> memo;

    bool canForm(const string& s) {
        if (memo.count(s))
            return memo[s];

        for (int i = 1; i < s.length(); ++i) {
            string prefix = s.substr(0, i);
            string suffix = s.substr(i);

            if (dict.count(prefix) && (dict.count(suffix) || canForm(suffix)))
                return memo[s] = true;
        }
        return memo[s] = false;
    }

   public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        dict.insert(words.begin(), words.end());
        vector<string> res;

        for (const string& s : words)
            if (canForm(s))
                res.push_back(s);

        return res;
    }
};