class Node {
public:
    Node* nodes[26];
    vector<string> matches;

    bool isComplete = false;

    Node() {
        for (auto &node : nodes) {
            node = nullptr;
        }
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void update_matches(vector<string>& matches, const string& word) {
        matches.insert(lower_bound(matches.begin(), matches.end(), word, [](const auto &a, const auto &b){ return a < b; }), word);
        if (matches.size() > 3) {
            matches.pop_back();
        }
    }
    
    void insert(string word) {
        Node* node = root;
        for (auto &ch: word) {
            int idx = ch - 'a';
            if (node->nodes[idx] == nullptr) {
                node->nodes[idx] = new Node();
            }
            update_matches(node->matches, word);
            node = node->nodes[idx];
        }
        node->isComplete = true;
        update_matches(node->matches, word);
    }
    
    vector<string> search(string word) {
        Node* node = root;
        for (auto &ch: word) {
            int idx = ch - 'a';
            if (node->nodes[idx] == nullptr) {
                return vector<string>{};
            }
            node = node->nodes[idx];
        }
        return node->matches;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for (auto &ch: prefix) {
            int idx = ch - 'a';
            if (node->nodes[idx] == nullptr) {
                return false;
            }
            node = node->nodes[idx];
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* trie = new Trie();
        for (auto & product : products) {
            trie->insert(product);
        }
        string query;
        vector<vector<string>> results;
        for (auto & ch : searchWord) {
            query += ch;
            results.push_back(trie->search(query));
        }
        return results;
    }
};
