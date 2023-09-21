// https://leetcode.com/problems/palindrome-linked-list

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
    public boolean isPalindrome(ListNode head) {
        
        if (head == null || head.next == null) {
            return true;
        }
        
        ListNode slow = head;
        ListNode fast = head.next;
        
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        ListNode first = head;
        ListNode second = slow.next;
        slow.next = null;
        
        second = reverseLL(second);
        
        while (first != null && second != null) {
            
            if (first.val != second.val) {
                return false;
            }
            
            first = first.next;
            second = second.next;
        }
        
        return true;
    }
    
    private ListNode reverseLL(ListNode head) {
        
        ListNode current = head;
        ListNode prev = null;
        
        while (current != null) {
            ListNode next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
}