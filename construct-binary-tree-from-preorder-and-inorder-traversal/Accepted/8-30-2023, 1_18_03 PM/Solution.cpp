// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

class Solution {
private:
	TreeNode* buildSubTree(vector<int> &preorder, vector<int> &inorder, int &preRootIndex, int left, int right, unordered_map<int, int> &inMap) {
		if(left > right) {
			return NULL;
		}
		
		// Find the index of the current root element of the preorder traversal in the inorder traversal
		// and then move to the next root index
		int inPivotIndex = inMap[preorder[preRootIndex++]];
		
		// Creation of new node
		TreeNode* node = new TreeNode(inorder[inPivotIndex]);
		
		// Recursively build the left sub-tree using the left elements present in the inorder traversal
		node->left = buildSubTree(preorder, inorder, preRootIndex, left, inPivotIndex - 1, inMap);
		
		// Recursively build the right sub-tree using the right elements present in the inorder traversal
		node->right = buildSubTree(preorder, inorder, preRootIndex, inPivotIndex + 1, right, inMap);
		
		return node;
	}
	
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preRootIndex = 0;
        unordered_map<int, int> inMap;
        
        // Mapping of inorder elements -> index
        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        
        return buildSubTree(preorder, inorder, preRootIndex, 0, inorder.size() - 1, inMap);
    }
};

