// https://leetcode.com/problems/minimum-distance-between-bst-nodes

class Solution {
    private:
        void traverse(TreeNode *root, vector<int> &inorderTrav) {
            if(root == NULL) {
                return;
            }

            traverse(root -> left, inorderTrav);
            inorderTrav.push_back(root -> val);
            traverse(root -> right, inorderTrav);
        }
    public:
        int minDiffInBST(TreeNode* root) {
            // Empty Tree
            if(root == NULL) {
                return 0;
            }

            vector<int> inorderTrav;
            traverse(root, inorderTrav);

            // for(int num : inorderTrav) {
            //     cout << num << " ";
            // }

            return inorderTrav[1] - inorderTrav[0];
        }
};

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)