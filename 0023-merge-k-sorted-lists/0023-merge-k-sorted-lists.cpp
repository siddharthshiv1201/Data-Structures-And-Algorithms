class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ans;
        for(int i=0; i<lists.size(); i++){
            ListNode* temp=lists[i];
            while(temp!=NULL){
                ans.push_back(temp->val);
                temp=temp->next;
            }
        }
        sort(ans.begin(),ans.end());

        ListNode* x=new ListNode(0);
        ListNode* cur=x;
        for(int i=0; i<ans.size(); i++){
            cur->next=new ListNode(ans[i]);
            cur=cur->next;
        }
        return x->next;



        
    }
};