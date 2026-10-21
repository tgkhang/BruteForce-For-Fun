/*
C2 (unordered_set ): 187 ms | 48.1 MB

C3 (string_view + unordered_set): 144 ms | 37.2 MB

C1 (Trie): 43 ms | 74.2 MB
*/

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
        string_view sv(sentence);  // Dùng view để duyệt không copy
        size_t i = 0, n = sentence.length();
        bool first = true;

        while (i < n) {
            size_t j = i;
            while (j < n && sentence[j] != ' ') j++;

            string_view word = sv.substr(i, j - i);
            string_view prefix = word.substr(0, 0);
            bool replaced = false;

            for (size_t k = 0; k < word.length(); ++k) {
                prefix = word.substr(0, k + 1);  // Lấy view O(1), không copy
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