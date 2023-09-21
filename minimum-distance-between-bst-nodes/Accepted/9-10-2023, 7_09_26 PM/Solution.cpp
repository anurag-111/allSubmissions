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

            for(int num : inorderTrav) {
                cout << num << " ";
            }

            int minDiff = INT_MAX;
            for(int i = 0; i < inorderTrav.size() - 1; i++) {
                minDiff = min(abs(inorderTrav[i] - inorderTrav[i + 1]), minDiff);
            }

            return minDiff;
        }
};

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)