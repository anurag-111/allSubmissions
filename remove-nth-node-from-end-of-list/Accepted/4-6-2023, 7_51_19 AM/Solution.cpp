// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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

/*Solution - I (One-Pointer, Two-Pass)
We just iterate in the first-pass to find the length of the linked list - len.
In the next pass, iterate len - n - 1 nodes from start and delete the next node (which would be nth node from end).
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        // iterate first n nodes using fast
        while(n--) {
            fast = fast -> next;
        }      

        // if fast is already null, it means we have to delete head itself. So, just return next of head.
        if(!fast) {
            return head -> next;
        }        

        // iterate till fast reaches the last node of list
        while(fast -> next) {
            fast = fast -> next;
            slow = slow -> next;
        }               
                        
        slow -> next = slow -> next -> next; // remove the nth node from last
        return head;
    }
};