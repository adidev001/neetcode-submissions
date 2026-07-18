class PrefixTree {

private:
struct node{
    bool isend;
    node* children[26];

    node(){
        isend=false;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }

};

node* root;
public:


    PrefixTree() {
        root=new node();
    }
    
    void insert(string word) {
        node* curr= root;

        for(char c:word){
            int index= c-'a';
            if(curr->children[index]==nullptr){
                curr->children[index]==new node();
            }

            curr=curr->childeren[index];
        }
        isend=true;
    }
    
    bool search(string word) {
        node* curr= root;
        for(char c: word){
            int index=c-'a';
            if(curr->children[index]==nullptr){
                return false;
            }
            curr=curr->children[index];
        }
        return curr->isend;
    }
    
    bool startsWith(string prefix) {
         node* curr= root;
        for(char c: word){
            int index=c-'a';
            if(curr->children[index]==nullptr){
                return false;
            }
            curr=curr->children[index];
        }
        return true;
    }
        
    }
};
