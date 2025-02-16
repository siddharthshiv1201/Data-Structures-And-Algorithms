//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after splitting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
  void LeftSub(Node* root, vector<int> &ans) {
    if (!root || (!root->left && !root->right)) {
        return;
    }
    ans.push_back(root->data);
    if (root->left)
        LeftSub(root->left, ans);
    else
        LeftSub(root->right, ans);
}

void Leaf(Node* root, vector<int>& ans) {
    if (!root) return;
    if (!root->left && !root->right) {
        ans.push_back(root->data);
        return; // Avoid unnecessary recursive calls
    }
    Leaf(root->left, ans);
    Leaf(root->right, ans);
}

void RightSub(Node* root, vector<int> &ans) {
    if (!root || (!root->left && !root->right)) {
        return;
    }

    if (root->right)
        RightSub(root->right, ans);
    else
        RightSub(root->left, ans);
    
    ans.push_back(root->data); // Push after recursion to maintain correct order
}

vector<int> boundaryTraversal(Node *root) {
    vector<int> ans;
    if (!root) return ans;

    ans.push_back(root->data);

    // Collect left boundary (excluding leaf nodes)
    LeftSub(root->left, ans);

    // Collect leaf nodes (excluding root)
    Leaf(root->left, ans);
    Leaf(root->right, ans);

    // Collect right boundary (excluding leaf nodes, collected in reverse order)
    RightSub(root->right, ans);

    return ans;
}

};

//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundaryTraversal(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends