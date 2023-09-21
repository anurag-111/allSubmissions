// https://leetcode.com/problems/copy-list-with-random-pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
    Node * copyRandomList(Node * head) {
     
      //Pass 1 : Creating a copy (except random pointer) of each old node
      // and insert it next to the old node it's copied from.
      
      Node * node = head;
      while (node) {
        Node* temp = node->next;
        node->next = new Node(node->val);
        node->next->next = temp;
        node = temp;
      }

      //Pass 2 : Now copy the random pointer (if exists) of the old
      //nodes to their copy of new nodes.
      
      node = head;
      while (node) {
        if (node->random) {
          node->next->random = node->random->next;
        }
        node = node->next->next;
      }

      //Pass 3 : Copy the alternative nodes into "ans" link list using
      //"helper" pointer along with restoring the old link list.
      
      Node* ans = new Node(0);
      Node* helper = ans;
        
      while (head) {
        helper->next = head->next;
        helper = helper->next;
        head->next = head->next->next;
        head = head->next;
      }
      
      return ans->next;
    }
};