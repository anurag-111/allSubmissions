// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii

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
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        // Create a dummy node with a value of 0, to handle cases where head itself is a duplicate
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Initialize two pointers: current (to traverse the list) and previous (to track the last distinct node)
        ListNode* current = head;
        ListNode* previous = dummy; 

        while (current != nullptr) {
            // Check if the next node exists and if it has the same value as the current node
            if (current->next != nullptr && current->val == current->next->val) {
                // Skip all consecutive nodes with the same value as the current node
                while (current->next != nullptr && current->val == current->next->val) {
                    current = current->next;
                }
                // Update previous's next pointer to skip the duplicate nodes
                previous->next = current->next;
            } else {
                // If no duplicates are found, move the previous pointer to the next distinct node
                previous = previous->next;
            }
            // Move the current pointer to the next node for the next iteration
            current = current->next;
        }

        // Return the modified list, starting from the next of the dummy node
        return dummy->next;
    }
};

// TC : O(N)
// SC : O(1)