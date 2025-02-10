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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr; // Edge case: Empty list

    ListNode* temp = head;
    std::vector<int> v;
    std::unordered_map<int, int> freq;

    // Store values in vector and count occurrences
    while (temp != nullptr) {
        v.push_back(temp->val);
        freq[temp->val]++;
        temp = temp->next;
    }

    // Create new linked list from elements that appear only once
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;

    for (int num : v) {
        if (freq[num] == 1) { // Keep only unique numbers
            curr->next = new ListNode(num);
            curr = curr->next;
        }
    }

    return dummy->next; // Return the updated list (excluding dummy node)
    }
};