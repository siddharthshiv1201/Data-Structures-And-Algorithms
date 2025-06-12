
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
         ListNode* prev=NULL;
         ListNode* curr=head;
         ListNode* Next=NULL;
         while(curr){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
         }
         return prev;

    }
};