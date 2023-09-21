// https://leetcode.com/problems/average-of-levels-in-binary-tree

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        
        queue <TreeNode*> nodeQueue;   
        nodeQueue.push(root);

        while(!nodeQueue.empty()) {      
            long double sum = 0;    
            double avg = 0;
            int levelSize = nodeQueue.size();
            
            for(int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                sum += currentNode->val;

                if(currentNode->left) {
                    nodeQueue.push(currentNode->left);
                } 
                if(currentNode->right) {
                    nodeQueue.push(currentNode->right);
                } 
            }   
            
            avg += double(sum / levelSize);
            ans.push_back(avg);         
        }

        return ans;
    }
};