// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void findParent(TreeNode *root, TreeNode *parent, unordered_map<TreeNode*,TreeNode*>&mp){
        
        if(!root) return;
        
        mp[root] = parent;
        findParent(root->left,root,mp);
        findParent(root->right,root,mp);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> result;
        if(!root) result;
        
        unordered_map<TreeNode*, TreeNode*>mp;
        
        findParent(root,NULL,mp);
        
        queue<pair<TreeNode*,int>>q;
        q.push({target, 0});

        unordered_set<TreeNode*> visited;
        
        while(!q.empty()){
            
            pair<TreeNode*, int> p = q.front();
            q.pop();
            
            TreeNode * cur = p.first;
            int dist = p.second;
            
            visited.insert(cur);
            
            if(dist == K)
                result.push_back(cur->val);

            if(cur->left && visited.count(cur->left)==0)
                q.push({cur->left, dist + 1});

            if(cur->right && visited.count(cur->right)==0)
                q.push({cur->right, dist + 1});

            if(mp[cur]!=NULL  && visited.count(mp[cur])==0)
                q.push({mp[cur], dist + 1});
            
        }
         return result;
    }
};