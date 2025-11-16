#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

typedef long long ll;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    TrieNode* failLink = nullptr;      // Failure link (suffix link)
    TrieNode* outputLink = nullptr;    // Next pattern ending node
    bool isEndOfWord = false;
    int patternLength = 0;             // Length of pattern ending here
};

class AhoCorasick {
public:
    TrieNode* root;
    
    AhoCorasick() {
        root = new TrieNode();
        root->failLink = root;  // Root fails to itself
    }
    
    // Insert pattern into trie
    void insert(string pattern) {
        TrieNode* cur = root;
        
        for (char ch : pattern) {
            if (cur->children.find(ch) == cur->children.end()) {
                cur->children[ch] = new TrieNode();
            }
            cur = cur->children[ch];
        }
        
        cur->isEndOfWord = true;
        cur->patternLength = pattern.length();
    }
    
    // Build failure links and output links using BFS
    void buildFailureLinks() {
        queue<TrieNode*> q;
        
        // Initialize root's children
        for (auto& [ch, child] : root->children) {
            child->failLink = root;  // Direct children fail to root
            q.push(child);
        }
        
        // BFS to build failure links
        while (!q.empty()) {
            TrieNode* current = q.front();
            q.pop();
            
            // Process each child
            for (auto& [ch, child] : current->children) {
                q.push(child);
                
                // Find failure link
                TrieNode* failNode = current->failLink;
                
                // Keep following failure links until we find a match or reach root
                while (failNode != root && 
                       failNode->children.find(ch) == failNode->children.end()) {
                    failNode = failNode->failLink;
                }
                
                // Set failure link
                if (failNode->children.find(ch) != failNode->children.end() && 
                    failNode->children[ch] != child) {
                    child->failLink = failNode->children[ch];
                } else {
                    child->failLink = root;
                }
                
                // Set output link
                if (child->failLink->isEndOfWord) {
                    child->outputLink = child->failLink;
                } else {
                    child->outputLink = child->failLink->outputLink;
                }
            }
        }
    }
    
    // Find all pattern matches in text
    vector<pair<int, string>> search(string text) {
        vector<pair<int, string>> matches;  // {end_position, pattern}
        TrieNode* current = root;
        
        for (int i = 0; i < text.length(); i++) {
            char ch = text[i];
            
            // Follow failure links until we find a match or reach root
            while (current != root && 
                   current->children.find(ch) == current->children.end()) {
                current = current->failLink;
            }
            
            // Move to next state if possible
            if (current->children.find(ch) != current->children.end()) {
                current = current->children[ch];
            }
            
            // Check for pattern matches at current position
            TrieNode* temp = current;
            while (temp != nullptr) {
                if (temp->isEndOfWord) {
                    matches.push_back({i, "pattern of length " + 
                                      to_string(temp->patternLength)});
                }
                temp = temp->outputLink;
            }
        }
        
        return matches;
    }
    
    // Get next state (for DP problems like CSES)
    TrieNode* getNextState(TrieNode* current, char ch) {
        // Follow failure links until we find a match or reach root
        while (current != root && 
               current->children.find(ch) == current->children.end()) {
            current = current->failLink;
        }
        
        // Move to next state if possible
        if (current->children.find(ch) != current->children.end()) {
            return current->children[ch];
        }
        
        return root;
    }
    
    // Get all patterns ending at this node (for DP)
    vector<int> getPatternsEndingHere(TrieNode* node) {
        vector<int> lengths;
        TrieNode* temp = node;
        
        while (temp != nullptr) {
            if (temp->isEndOfWord) {
                lengths.push_back(temp->patternLength);
            }
            temp = temp->outputLink;
        }
        
        return lengths;
    }
};

// Example usage
int main() {
    AhoCorasick ac;
    
    // Insert patterns
    ac.insert("ab");
    ac.insert("abab");
    ac.insert("c");
    
    // Build automaton
    ac.buildFailureLinks();
    
    // Search for patterns
    string text = "ababc";
    auto matches = ac.search(text);
    
    cout << "Found " << matches.size() << " matches:\n";
    for (auto& [pos, pattern] : matches) {
        cout << "Position " << pos << ": " << pattern << endl;
    }
    
    return 0;
}