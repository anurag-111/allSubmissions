// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

class Solution {
private:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentTrack, TreeNode* target) {
        // Mapping : node -> parent

        // Queue for storage
        queue<TreeNode*> nodes;
        nodes.push(root);

        // Traversal over the tree
        while(!nodes.empty()) {
            TreeNode* current = nodes.front();
            nodes.pop();

            // Check for left node
            if(current -> left) {
                nodes.push(current -> left);
                parentTrack[current -> left] = current;
            }

            // Check for the right node
            if(current -> right) {
                nodes.push(current -> right);
                parentTrack[current -> right] = current;
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Mapping of child -> node
        unordered_map<TreeNode*, TreeNode*> parentTrack;

        // Function call for parent mapping
        markParent(root, parentTrack, target);

        // Queue for traversal storage
        queue<TreeNode*> nodes;
        nodes.push(root);

        // Visited mapping
        unordered_map<TreeNode*, bool> visited;

        // Current level indicator
        int currentLevel = 0;

        while(!nodes.empty()) {
            // Size of the current tree level
            int size = nodes.size();

            if(currentLevel == k) {
                break;
            }

            currentLevel++;

            // Traversing through the level
            for(int i = 0; i < size; i++) {
                TreeNode* current = nodes.front();
                nodes.pop();

                if(current -> left != NULL && !visited[current -> left]) {
                    nodes.push(current -> left);
                    visited[current -> left] = true;
                }

                if(current -> right != NULL && !visited[current -> right]) {
                    nodes.push(current -> right);
                    visited[current -> right] = true;
                }

                if(parentTrack[current] != NULL && !visited[parentTrack[current]]) {
                    nodes.push(parentTrack[current]);
                    visited[parentTrack[current]] = true;
                }
            }
        }

        vector<int> result;
        while(!nodes.empty()) {
            TreeNode *current = nodes.front();
            nodes.pop();
            result.push_back(current -> val);
        }

        return result;

    }
};