#include <unordered_map>
using namespace std;

class LRUCache {
private:
    struct node {
        int key;
        int val;
        node* next = nullptr;
        node* prev = nullptr;

        node(int k, int v) {
            key = k;
            val = v; // Fixed typo: 'value' to 'v'
        }
    };

    int cap; // We need to store the capacity for the whole class to see
    node* left;
    node* right;
    unordered_map<int, node*> cache;

    void removeNode(node* del) {
        node* prevNode = del->prev;
        node* nextNode = del->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void addNode(node* r) {
        node* prevv = right->prev;
        right->prev = r;
        r->prev = prevv;
        prevv->next = r;
        r->next = right;
    }

public:
    LRUCache(int capacity) {
        cap = capacity; 
        left = new node(0, 0);
        right = new node(0, 0);

        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            node* cal = cache[key];
            
            removeNode(cal);
            addNode(cal);
            
            return cal->val;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            node* cal = cache[key];
            cal->val = value; 
            
            removeNode(cal);
            addNode(cal);
        }
        else {
            node* cal = new node(key, value);
            cache[key] = cal; 
            addNode(cal);     
            
            if(cache.size() > cap) {
                node* lru = left->next;
                
                cache.erase(lru->key);
                
                removeNode(lru);
                
                delete lru; 
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */