// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

// val, left, rigght
class Solution {
private:
    TreeNode* buildBST(vector<int> &nums, int start, int end) {
        if(start > end) {
            return NULL;
        }

        int mid = start + (end - start) / 2;
        int nodeValue = nums[mid];
        TreeNode *newNode = new TreeNode(nodeValue);
        newNode -> left = buildBST(nums, start, mid - 1);
        newNode -> right = buildBST(nums, mid + 1, end);

        return newNode;
    }

public:
    TreeNode* sortedArrayToBST(vector<int> &nums) {
        int start = 0;
        int end = nums.size() - 1;
        return buildBST(nums, start, end);
    }
};