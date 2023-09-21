// https://leetcode.com/problems/reverse-nodes-in-k-group

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pointer = dummy;
        while (pointer != NULL) {
            ListNode* temp = pointer;
            // Firstly we check whether there are k nodes available or not
            for (int i = 0; (i < k) && (temp != NULL); i++) {
                temp = temp->next;
            }
            if (temp == NULL) {
                break;
            }
            
            ListNode* prev = NULL;
            ListNode* curr = pointer->next;
            ListNode* next = NULL;
            
            for (int i = 0; i < k; i++) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            // 0 (pointer) -> 1 <- 2 <- 3 (prev)    4 (curr) -> 5 -> 6 -> 7
            // idea is to link the pointer to 3 and link 1 to 4:    
            
            ListNode* tail = pointer->next;
            tail->next = curr;
            pointer->next = prev;
            pointer = tail;
        }
        return dummy->next;
    }
};