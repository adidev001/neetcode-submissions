class PrefixTree {
private:
    // We can nest the node structure privately inside the class!
    // This keeps our code clean and hides the node logic from the outside.
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;

        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    
    TrieNode* root;

public:
    PrefixTree() {
        // Initialize the root as an empty starting node
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        
        for (char c : word) {
            int index = c - 'a';
            
            // Create the path if it doesn't exist yet
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            
            // Move down the path
            node = node->children[index];
        }
        
        // Mark the final node as the end of a valid word
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        
        for (char c : word) {
            int index = c - 'a';
            
            // If the path breaks, the word cannot exist
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        
        // Return true ONLY if we landed on an official "end of word" flag
        return node->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        
        for (char c : prefix) {
            int index = c - 'a';
            
            // If the path breaks, the prefix doesn't exist
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        
        // We survived the whole prefix path, so it must exist!
        return true;
    }
};

/**
 * Your PrefixTree object will be instantiated and called as such:
 * PrefixTree* obj = new PrefixTree();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */