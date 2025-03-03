//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends

/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverse(Node* head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        
        Node* prev=nullptr;
        Node* curr=head;
        Node* forward=nullptr;
        
        while(curr!=nullptr){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
  
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        while(num1->data==0){
            num1=num1->next;
        }
        while(num2->data==0){
            num2=num2->next;
        }
        
        Node* head1=reverse(num1);
        Node* head2=reverse(num2);
        
        Node* dummyhead=new Node(-1);
        Node* dummytail=dummyhead;
        
        int carry=0;
        while(head1!=nullptr && head2!=nullptr){
            int sum=carry+head1->data+head2->data;
            carry=sum/10;
            int digit=sum%10;
            
            Node* newnode=new Node(digit);
            dummytail->next=newnode;
            dummytail=newnode;
            head1=head1->next;
            head2=head2->next;
        }
        
        while(head1!=nullptr){
            int sum=carry+head1->data;
            carry=sum/10;
            int digit=sum%10;
            
            Node* newnode=new Node(digit);
            dummytail->next=newnode;
            dummytail=newnode;
            head1=head1->next;
        }
        
        while(head2!=nullptr){
            int sum=carry+head2->data;
            carry=sum/10;
            int digit=sum%10;
            
            Node* newnode=new Node(digit);
            dummytail->next=newnode;
            dummytail=newnode;
            head2=head2->next;
        }
        
        if(carry){
            Node* newnode=new Node(carry);
            dummytail->next=newnode;
            newnode=dummytail;
        }
        
        dummyhead=reverse(dummyhead->next);
        
        return dummyhead;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends