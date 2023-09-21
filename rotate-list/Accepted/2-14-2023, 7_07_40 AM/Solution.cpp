// https://leetcode.com/problems/rotate-list

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
    ListNode* rotateRight(ListNode* head, int k) {
        // edge cases
        if (!head || !head->next || k == 0) {
            return head;
        }

        // calculate the length of the linked list
        ListNode *cur = head;
        int len = 1;
        while (cur->next) {
            cur = cur->next;
            len++;
        }

        // reaching the end
        cur->next = head;   
        k = k % len;
        k = len - k;
        while (k--) {
            cur = cur->next;
        }

        // updating the head and removing the link
        head = cur->next;
        cur->next = NULL;
        
        return head;
    }
};
