class WordDictionary {
private:
    struct node {
        bool end;
        node* children[26];

        node() {
            end = false;
            for(int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    node* root;

public:
    WordDictionary() {
        root = new node();
    }
    
    void addWord(string word) {
        node* curr = root;
        for(char c : word) {
            int index = c - 'a';
            if(curr->children[index] == nullptr) {
                curr->children[index] = new node();
            }
            curr = curr->children[index];
        }
        curr->end = true; // FIX: Assign to curr
    }
    
    bool searchhelp(node* curr, string word) {
        // FIX: Use a standard for-loop so we have access to the index 'i'
        for(int i = 0; i < word.length(); i++) {
            char ch = word[i];
            
            if(ch == '.') {
                for(int j = 0; j < 26; j++) {
                    // FIX: Use 'j' here, not 'i'
                    if(curr->children[j] != nullptr) {
                        // FIX: Substring works now because 'i' exists
                        if(searchhelp(curr->children[j], word.substr(i + 1)) == true) {
                            return true;
                        }
                    }
                }
                return false;
            } 
            else {
                if (curr->children[ch - 'a'] == nullptr) {
                    return false;
                }
                curr = curr->children[ch - 'a'];
            }
        }
        return (curr != nullptr && curr->end == true);
    }
    
    bool search(string word) {
        // FIX: Must return the result
        return searchhelp(root, word); 
    }
};