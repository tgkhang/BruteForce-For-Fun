class Solution {
    struct Node {
        Node* child[26];
        int x;
        Node() : x(0) { fill(child, child + 26, nullptr); }
    };

    Node* root;

    void insert(const string& s) {
        Node* cur = root;

        for (char c : s) {
            if (cur->child[c - 'a'] == nullptr)
                cur->child[c - 'a'] = new Node();

            cur = cur->child[c - 'a'];

            // increase number of word to the next node
            cur->x++;
        }
    }

    int score(const string& s) {
        Node* cur = root;

        int tmp = 0;

        for (char c : s) {
            cur = cur->child[c - 'a'];
            tmp += cur->x;
        }

        return tmp;
    }

   public:
    vector<int> sumPrefixScores(vector<string>& words) {
        root = new Node();
        for (const string& i : words)
            insert(i);

        vector<int> res;

        for (const string& s : words)
            res.push_back(score(s));

        return res;
    }
};


//==========================================
class Solution {
   public:
    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<string, int> mp;

        for (const string& w : words) {
            string prefix = "";
            for (char c : w) {
                prefix += c;
                mp[prefix]++;
            }
        }

        vector<int> res;
        for (const string& w : words) {
            int total = 0;
            string prefix = "";
            for (char c : w) {
                prefix += c;
                total += mp[prefix];
            }
            res.push_back(total);
        }

        return res;
    }
};