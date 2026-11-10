#include <bits/stdc++.h>
using namespace std;

/**
 * =================================================================================================
 * 14. Longest Common Prefix
 * =================================================================================================
 */

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

/**
 * =================================================================================================
 * 208. Implement Trie (Prefix Tree)
 * =================================================================================================
 */

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

/**
 * =================================================================================================
 * 211. Design Add and Search Words Data Structure
 * =================================================================================================
 */

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

/**
 * =================================================================================================
 * 472. Concatenated Words
 * =================================================================================================
 */

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

/**
 * =================================================================================================
 * 648. Replace Words
 * =================================================================================================
 */

/*
C2 (unordered_set ): 187 ms | 48.1 MB

C3 (string_view + unordered_set): 144 ms | 37.2 MB

C1 (Trie): 43 ms | 74.2 MB
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Node {
        bool isEnd;
        Node* child[26];
        Node() : isEnd(false) {
            fill(child, child + 26, nullptr);
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

    string findRoot(const string& word) {
        Node* cur = root;
        string prefix;

        for (char c : word) {
            if (cur->child[c - 'a'] == nullptr) return word;
            cur = cur->child[c - 'a'];
            prefix += c;
            if (cur->isEnd) return prefix;
        }
        return word;
    }

   public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        for (string& s : dictionary) insert(s);
        string res = "";
        istringstream iss(sentence);
        string word;
        bool first = true;
        while (iss >> word) {
            if (!first) res += ' ';
            first = false;
            res += findRoot(word);
        }
        return res;
    }
};

//c2
class Solution {
   public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> roots(dictionary.begin(), dictionary.end());

        string res;
        istringstream iss(sentence);
        string word;
        bool first = true;

        while (iss >> word) {
            if (!first) res += ' ';
            first = false;

            string prefix;
            bool replaced = false;
            for (char c : word) {
                prefix += c;
                if (roots.count(prefix)) {
                    res += prefix;
                    replaced = true;
                    break;
                }
            }
            if (!replaced) res += word;
        }
        return res;
    }
};

//c3

class Solution {
   public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string_view> roots;
        for (const auto& s : dictionary) roots.insert(s);

        string res;
        string_view sv(sentence);
        size_t i = 0, n = sentence.length();
        bool first = true;

        while (i < n) {
            size_t j = i;
            while (j < n && sentence[j] != ' ') j++;

            string_view word = sv.substr(i, j - i);
            string_view prefix = word.substr(0, 0);
            bool replaced = false;

            for (size_t k = 0; k < word.length(); ++k) {
                prefix = word.substr(0, k + 1);  
                if (roots.count(prefix)) {
                    if (!first) res += ' ';
                    first = false;
                    res += prefix;
                    replaced = true;
                    break;
                }
            }
            if (!replaced) {
                if (!first) res += ' ';
                first = false;
                res += word;
            }
            i = j + 1;
        }
        return res;
    }
};

/**
 * =================================================================================================
 * 677. Map Sum Pairs
 * =================================================================================================
 */

#include<bits/stdc++.h>
using namespace std;

class MapSum {
   private:
    unordered_map<string, int> t;
   public:
    MapSum() {}
    void insert(string key, int val) { t[key] = val; }
    int sum(string prefix) {
        int res = 0;

        for (auto& [key, val] : t) {
            if (key.rfind(prefix, 0) == 0) {  
                // no start with funciton so use rfind
                // find prefix in key, from position 0
                res += val;
            }
        }
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */


//c2

class MapSum {
    struct Node {
        Node* child[26];
        int val;
        Node() : val(0) { fill(child, child + 26, nullptr); }
    };

    Node* root;

    int dfsSum(Node* node) {
        if (!node) return 0;
        int total = node->val;
        for (int i = 0; i < 26; ++i) 
            total += dfsSum(node->child[i]);
        return total;
    }

   public:
    MapSum() { root = new Node(); }

    void insert(string key, int val) {
        Node* cur = root;
        for (char c : key) {
            int idx = c - 'a';
            if (!cur->child[idx]) cur->child[idx] = new Node();
            cur = cur->child[idx];
        }
        cur->val = val;  // Ghi đè tự động nếu insert lại
    }

    int sum(string prefix) {
        Node* cur = root;
        for (char c : prefix) {
            if (!cur->child[c - 'a']) return 0;
            cur = cur->child[c - 'a'];
        }
        return dfsSum(cur);
    }
};

    struct TrieNode {
        TrieNode* child[26];
        int sum;  // Tổng giá trị của tất cả các key đi qua node này
        TrieNode() : sum(0) {
            fill(child, child + 26, nullptr);
        }
    };

    TrieNode* root;
    unordered_map<string, int> mp;  // Lưu key -> val để xử lý ghi đè

   public:
    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        int diff = val;
        // Nếu key đã tồn tại, hiệu số cần cập nhật là (val - val_cũ)
        if (mp.count(key)) {
            diff = val - mp[key];
        }
        mp[key] = val;  // Cập nhật lại giá trị mới

        TrieNode* cur = root;
        for (char c : key) {
            int idx = c - 'a';
            if (!cur->child[idx]) {
                cur->child[idx] = new TrieNode();
            }
            cur = cur->child[idx];
            cur->sum += diff;  // Cộng phần chênh lệch vào mọi node trên đường đi
        }
    }

    int sum(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!cur->child[idx]) return 0;  // Không có prefix này
            cur = cur->child[idx];
        }
        return cur->sum;  // Trả về tổng đã lưu sẵn ở node cuối cùng của prefix
    }
};

/**
 * =================================================================================================
 * 720. Longest Word in Dictionary
 * =================================================================================================
 */

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

/**
 * =================================================================================================
 * 1268. Search Suggestions System
 * =================================================================================================
 */

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

/**
 * =================================================================================================
 * 2416. Sum of Prefix Scores of Strings
 * =================================================================================================
 */

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
