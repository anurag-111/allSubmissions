// https://leetcode.com/problems/merge-two-sorted-lists

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Case 1 : If either of the linked lists are NULL
        if (list1 == NULL) {
            return list2;
        }

        if(list2 == NULL) {
            return list1;
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        // Case 2 : Traverse till there are nodes present in both the lists
        while(ptr1 != NULL && ptr2 != NULL) {
            if(ptr1 -> val <= ptr2 -> val) {
                current -> next = ptr1;
                ptr1 = ptr1 -> next;
            } else {
                current -> next = ptr2;
                ptr2 = ptr2 -> next;
            }
            current = current -> next;
        }

        // Case 3 : Left over elements
        if(ptr1 != NULL) {
            current -> next = ptr1;
        }

        if(ptr2 != NULL) {
            current -> next = ptr2;
        }

        return dummy -> next;
    }
};

// Time Complexity: O(m + n) - where 'm' is the length of list l1 and 'n' is the length of list l2.
// Space Complexity: O(1) - constant space usage regardless of input list sizes.