class TrieNode {
    friend class Trie;
public:
    // Initialize your data structure here.
    TrieNode() {
        is_key = false;
        // memset(children, NULL, 26);
        // NOT fucking work!!
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
private:
    bool is_key;
    TrieNode* children [26];
};

// all inputs are consist of lowercase letters a-z
class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        for (char c : word) {
            int id = c - 'a';
            if ( !p->children[id] ) {
                p->children[id] = new TrieNode ( );
            }
            p = p->children[id];
        }
        p->is_key = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = root;
        for (char c : word) {
            int id = c - 'a';
            if (!p->children[id]) {
                return false;
            }
            else {
                p = p->children[id];
            }
        }
        
        return p->is_key;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (char c : prefix) {
            int id = c - 'a';
            if (!p->children[id]) {
                return false;
            }
            else {
                p = p->children[id];
            }
        }
        
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
