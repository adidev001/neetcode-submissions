/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            size++;
        }

        int index=size-n;

        if(index==0){
            ListNode* temp=head;
            head=head->next;
            delete temp;
            return head;
            
        }
        int steps=0;
        ListNode* temp1=head;
        while(steps!=index-1){
            steps++;
            temp1=temp1->next;
        }
        ListNode* curr=temp1;
        ListNode* nextt=temp1->next->next;
        curr->next=nextt;

        return head;


    }
};
