class WordDictionary {
private:
struct node{
    bool end;
    node* children[26];

    node(){
        end=false;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
};

node* root;
public:
    WordDictionary() {
        root=new node();
        
    }
    
    void addWord(string word) {
         node* curr= root;
        for(char c: word){
            int index=c-'a';
            if(curr->children[index]==nullptr){
                curr->children[index]=new node();
            }
            curr=curr->children[index];
        }
        end=true;
    }
    bool searchhelp(node* root,string word){
        node*curr=root;
        for(char c: word){
            if(ch=='.'){
                for(int j=0;j<26;j++){
                    if(curr->children[i]!=nullptr){
                        if(searchhelp(curr->children[j],word.substr(i+1))==true){
                            return true;
                        }
                    }
                }return false;
            }

            else if (curr->children[ch-'a']==nullptr){
                return false;
            }

            curr=curr->children[ch-'a'];
        }
        return (curr!=nullptr && curr->end==true);
    }
    bool search(string word) {
        searchhelp(root,word);
    }
};
