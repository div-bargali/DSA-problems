class TrieNode {
public:
    TrieNode* links[26];
    bool isEnd;
    
    bool containsChar(char c) {
        // returns true, if root's link array has reference to char c
        return links[c-'a'] != nullptr; 
    }
};

class Trie {
private: 
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (node->containsChar(c)) {
                // if node contains char c, then move to it's link node
                node = node->links[c-'a']; // for 0-based index
            } else {
                // create a link in curr node, to the char c
                // basically, curr node's link array's c-'a' th index will
                // point to a new TrieNode
                node->links[c-'a'] = new TrieNode();
                node = node->links[c-'a'];
            }
        }
        // word is parsed, set the isEnd true for last node
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (node->containsChar(c)) {
                node = node->links[c-'a'];
            } else {
                return false;
            }
        }
        // since string word is parsed, node should point to a TrieNode
        // with isEnd flag set to true
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            char c = prefix[i];
            if (node->containsChar(c)) {
                node = node->links[c - 'a'];
            } else {
                return false;
            }
        }
        // since string word is parsed, Trie contains a word that startsWith 
        // the prefix
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