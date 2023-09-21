// https://leetcode.com/problems/recover-binary-search-tree

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
public:
    TreeNode *prevNode = NULL;
    TreeNode *firstPoint = NULL;
    TreeNode *endPoint = NULL;

    void findSegment(TreeNode *root) {
        if(root == NULL) {
            return;
        }

        findSegment(root -> left);

        if(prevNode) {
            if(prevNode -> val > root -> val) {
                if(firstPoint == NULL) {
                    firstPoint = prevNode;
                }
                endPoint = root;
            }
        }

        prevNode = root;
        findSegment(root -> right);
    }
    void recoverTree(TreeNode* root) {
        if(root == NULL) {
            return;
        }

        findSegment(root);

        int temp = firstPoint -> val;
        firstPoint -> val = endPoint -> val;
        endPoint -> val = temp;
    }
};