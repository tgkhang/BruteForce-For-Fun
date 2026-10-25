class Solution {
    struct Node {
        Node* child[26];
        vector<string> suggestions;

        Node() { fill(child, child + 26, nullptr); }
    };

    Node* root = new Node();

    void insert(const string& product) {
        Node* cur = root;
        for (char c : product) {
            if (cur->child[c - 'a'] == nullptr)
                cur->child[c - 'a'] = new Node();

            cur = cur->child[c - 'a'];
            if (cur->suggestions.size() < 3)
                cur->suggestions.push_back(product);
        }
    }

   public:
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
        sort(products.begin(), products.end());

        for (const string& s : products)
            insert(s);

        vector<vector<string>> res;
        Node* cur = root;
        bool canSearch = true;

        for (char c : searchWord) {
            if (!canSearch) {
                res.push_back({});
                continue;
            }

            if (cur->child[c - 'a']) {
                cur = cur->child[c - 'a'];
                res.push_back(cur->suggestions);
            } else {
                canSearch = false;
                res.push_back({});
            }
        }
        return res;
    }
};