// https://leetcode.com/problems/linked-list-in-binary-tree

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool Check(ListNode* head, TreeNode* root) {
        if(head == NULL) {
            return true;
        }
        if (root == NULL || root->val != head->val) {
            return false;
        }
        // head->val = root->val
        return Check(head->next, root->left) || Check(head->next, root->right);
    }
    bool SubPathCheck(ListNode* head, TreeNode* root) {
        if(root == NULL) {
            return false;
        }
        if(Check(head, root)) {
            return true;
        }
        return SubPathCheck(head, root->left) || SubPathCheck(head, root->right);
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return SubPathCheck(head, root);
    }
};







