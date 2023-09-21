// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

class Solution {
private: 
    TreeNode* buildSubTree(vector<int> &inorder, vector<int> &postorder,int &postIndex, int left, int right, unordered_map<int, int> &inMap) {
        if(left > right) {
            return NULL;
        }
        
        int inPivotIndex = inMap[postorder[postIndex--]];
        TreeNode* node = new TreeNode(inorder[inPivotIndex]);
        
        node -> right = buildSubTree(inorder, postorder, postIndex, inPivotIndex + 1, right, inMap);
        node -> left = buildSubTree(inorder, postorder, postIndex, left, inPivotIndex - 1, inMap);
        
        return node;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size() - 1;
        
        unordered_map<int, int> inMap;
        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        
        return buildSubTree(inorder, postorder, postIndex, 0, inorder.size() - 1, inMap);      
    }
};