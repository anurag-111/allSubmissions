// https://leetcode.com/problems/reverse-linked-list

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
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = NULL;
        ListNode* current = head;
        ListNode* nextNode = NULL;

        while(current != nullptr) {
            nextNode = current -> next;
            current -> next = previous;
            previous = current;
            current = nextNode;
        }

        return previous;
    }
};

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)