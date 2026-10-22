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