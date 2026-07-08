class MyCircularQueue {
   private:
    struct node {
        int val;
        node* next;
        node* prev;

        node(int v) {
            val = v;
            next = nullptr;
            prev = nullptr;
        }
    };
    int space;
    node* left;
    node* right;

   public:
    MyCircularQueue(int k) {
        space = k;
        left = new node(0);
        right = new node(0);

        left->next = right;
        right->prev = left;
    }

    bool enQueue(int value) {
        if (isFull()) return false;

        node* newnode = new node(value);

        node* last = right->prev;
        last->next = newnode;
        newnode->prev = last;
        newnode->next = right;
        right->prev = newnode;
        space--;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        node* first = left->next;
        left->next = first->next;
        first->next->prev = left;
        space++;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return left->next->val;
    }

    int Rear() {
        if (isEempty()) return -1;

        return right->prev->val;
    }

    bool isEmpty() { return (left->next = right); }

    bool isFull() { return (space == 0); }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */