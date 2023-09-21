// https://leetcode.com/problems/add-two-numbers-ii

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        
        if (l1 == null) {
            return l2;
        } else if (l2 == null) {
            return l1;
        }
        
        ListNode first = reverse(l1);
        ListNode second = reverse(l2);
        
        return reverse(addLists(first, second));
    }
    
    private ListNode addLists(ListNode first, ListNode second) {
        
        ListNode dummy = new ListNode(-1);
        ListNode temp = dummy;
        
        
        ListNode pFirst = first;
        ListNode pSecond = second;
        int carry = 0;
        
        while (pFirst != null || pSecond != null) {
            
            int a = pFirst != null ? pFirst.val : 0;
            int b = pSecond != null ? pSecond.val : 0;
            
            int sum = a + b + carry;
            
            carry = sum / 10;
            
            sum = sum % 10;
            
            temp.next = new ListNode(sum);
            temp = temp.next;
            
            pFirst = pFirst != null ? pFirst.next : null;
            pSecond = pSecond != null ? pSecond.next : null;
        }
        
        if (carry > 0) {
            temp.next = new ListNode(carry);
        }
        
        return dummy.next;
    }
    
    private ListNode reverse(ListNode head) {
        
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode prev = null;
        ListNode current = head;
        ListNode next;
        
        while (current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
}