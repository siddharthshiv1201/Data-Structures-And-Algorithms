class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        string s1="";
        string s2="";
        Node* temp1=first;
        Node* temp2=second;
        while(temp1!=NULL){
           s1+=to_string(temp1->data);
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            s2+=to_string(temp2->data);
            temp2=temp2->next;
        }
        long long  a=stoll(s1);
        long long  b=stoll(s2);
        
        long long mul=a*b;
        mul=mul%1000000007;
        return mul;
        
    }
};