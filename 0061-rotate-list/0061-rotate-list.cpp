
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||  head->next==NULL){
            return head;
        }
        int n=1;
        ListNode* tail=head;
        while(tail->next){
            n++;
            tail=tail->next;
        }

        k=k%n;
        if(k==0) return head;

        ListNode* new_tail=head;
        for(int i=1; i<n-k; i++){
            new_tail=new_tail->next;
        }
        ListNode* new_head=new_tail->next;
        new_tail->next=NULL;
        tail->next=head;

        return new_head;
        
    }
};