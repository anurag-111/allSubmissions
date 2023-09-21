// https://leetcode.com/problems/add-two-numbers-ii

class Solution {
private:
    ListNode* reverse(ListNode *head) {
        ListNode *prevNode = NULL;
        ListNode *currNode = head;
        ListNode *nextNode = NULL;

        while(currNode) {
            nextNode = currNode -> next;
            currNode -> next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }

        return prevNode;
    }

ListNode* add(ListNode *head1, ListNode *head2) {
    int carry = 0;
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;

    while(head1 || head2 || carry) {
        int sum = 0;

        if(head1) {
            sum += head1 -> val;
            head1 = head1 -> next;
        }

        if(head2) {
            sum += head2 -> val;
            head2 = head2 -> next;
        }

        sum += carry;
        carry = sum / 10;

        ListNode *newNode = new ListNode(sum % 10);
        current -> next = newNode;
        current = current -> next;
    }

    return dummy -> next;
}


public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head1 = reverse(l1);
        ListNode *head2 = reverse(l2);

        return reverse(add(head1, head2));
    }
};