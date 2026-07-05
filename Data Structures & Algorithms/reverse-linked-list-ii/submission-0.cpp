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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);

        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        int l = left - 1;
      
        while (l != 0) {
            slow = slow->next;
            l--;
        }
        // Move fast pointer by (right - left + 1) steps
        for (int i = 0; i < (right - left + 1); ++i) {
            fast = fast->next;
        }
        ListNode* sub=slow->next;
        slow->next=nullptr;
        ListNode* temp=fast->next;
        fast->next=nullptr;

        ListNode* prev=nullptr;
        ListNode* curr=sub;
        ListNode* next=nullptr;

        while(curr){
            next=curr->next;
            curr->next=prev;

            prev=curr;
            curr=next;
        }
        slow->next=prev;
        fast->next=temp;
        return head;
    }
};