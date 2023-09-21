// https://leetcode.com/problems/maximum-width-of-binary-tree

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


 /*
    Approach:
    The code uses a breadth-first search (BFS) approach to traverse the binary tree level by level using a queue 
    data structure. Each element in the queue is a pair of a TreeNode pointer and an integer representing its position (index) 
    in that level. The root node is initially pushed into the queue with a position of 0.

*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        int maxWidth = 1;

        /* 
            The outer while loop continues until the queue is empty, which means all levels of the binary 
            tree have been processed. Inside the loop, two variables start and end are used to keep track 
            of the starting and ending positions of the nodes at the current level. The width of the current 
            level is calculated as end - start + 1, and maxWidth is updated with the maximum width seen so far. 
        */

        while(!q.empty()){
            int start = q.front().second;
            int end = q.back().second;
            
            maxWidth = max(maxWidth, end - start + 1);
            
            int count = q.size();
            
            /* 
                A nested while loop is used to process all the nodes at the current level. 
                The variable count keeps track of the number of nodes at the current level, which 
                is initially set to the size of the queue.  
            */

            while(count--){
                /*
                    Calculate the relative position (index) of the current node in the current level. 
                    It subtracts the ending position (end) from the position of the current node (q.front().second). 
                    This gives the position of the current node with respect to the last node in the current level.
                */
                int idx = q.front().second - end;
                
                TreeNode* node = q.front().first;            
                q.pop();
                
                if(node->left) {
                    q.push({node->left, 2 * idx + 1});
                }
                    
                if(node->right) {
                    q.push({node->right, 2 * idx + 2});
                }
            }
        }
        
        return maxWidth;
    }
};