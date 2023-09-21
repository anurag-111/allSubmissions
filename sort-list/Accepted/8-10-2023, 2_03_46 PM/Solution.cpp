// https://leetcode.com/problems/sort-list

class Solution {
private:
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* mergeLists(ListNode* left, ListNode* right) {
        if(left == NULL) {
            return right;
        }

        if(right == NULL) {
            return left;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        while(left && right) {
            if(left->val < right->val) {
                current -> next = left;
                left = left -> next;
            } else {
                current -> next = right;
                right = right -> next; 
            }
            current = current -> next;
        }

        if(left != NULL) {
            current -> next = left;
        }

        if(right != NULL) {
            current -> next = right;
        }

        return dummy -> next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }
        
        ListNode* mid = findMid(head);
        ListNode* newHead = mid -> next;

        mid -> next = NULL;

        ListNode* leftHalf = sortList(head);
        ListNode* rightHalf = sortList(newHead);

        return mergeLists(leftHalf, rightHalf);
    }
};