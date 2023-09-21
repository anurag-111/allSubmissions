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
        ListNode* iter = head;
        int len = 0, i = 1;
        while(iter){                       // finding the length of linked list
            iter = iter -> next;
            len++;
        }
        if(len == n)                       // if head itself is to be deleted
            head = head -> next;
        for(iter = head; i < len - n; i++) // iterate first len-n nodes
            iter = iter -> next;
        iter -> next = iter -> next -> next; 
        return head;
    }
};