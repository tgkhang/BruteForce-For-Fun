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

// thu hep l , r khi go them
class Solution {
   public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        for (auto i : products) cout << i << " ";

        vector<vector<string>> res;

        int l = 0, r = products.size() - 1;

        for (int i = 0; i < searchWord.length(); ++i) {
            char c = searchWord[i];
            // Tìm sản phẩm đầu tiên có ký tự thứ i >= c
            while (l <= r &&
                   (products[l].length() <= i || products[l][i] < c)) {
                l++;
            }
            // Tìm sản phẩm cuối cùng có ký tự thứ i <= c
            while (l <= r &&
                   (products[r].length() <= i || products[r][i] > c)) {
                r--;
            }

            vector<string> temp;
            for (int k = l; k <= min(r, l + 2); ++k) {
                temp.push_back(products[k]);
            }
            res.push_back(temp);
        }

        return res;
    }
};
