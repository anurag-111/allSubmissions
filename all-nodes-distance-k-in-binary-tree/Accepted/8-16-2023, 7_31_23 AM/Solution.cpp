// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

class Solution {
private:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentTrack, TreeNode* target) {
        // Mapping: node -> parent

        // Queue for storage
        queue<TreeNode*> nodes;
        nodes.push(root);

        // Traversal over the tree
        while (!nodes.empty()) {
            TreeNode* current = nodes.front();
            nodes.pop();

            // Check for left node
            if (current->left) {
                nodes.push(current->left);
                parentTrack[current->left] = current;
            }

            // Check for the right node
            if (current->right) {
                nodes.push(current->right);
                parentTrack[current->right] = current;
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Mapping of child -> parent
        unordered_map<TreeNode*, TreeNode*> parentTrack;

        // Function call for parent mapping
        markParent(root, parentTrack, target);

        // Queue for traversal storage
        queue<TreeNode*> nodes;
        nodes.push(target);  // Start from the target node

        int currentLevel = 0;

        // Set to track visited nodes
        unordered_set<TreeNode*> visited;
        visited.insert(target);  // Mark the target node as visited

        // Traverse through the levels
        while (!nodes.empty()) {
            int size = nodes.size();

            if (currentLevel == k) {
                break;  // Reached the desired distance
            }

            // Traversing through the level
            for (int i = 0; i < size; i++) {
                TreeNode* current = nodes.front();
                nodes.pop();

                if (current->left && visited.find(current->left) == visited.end()) {
                    nodes.push(current->left);
                    visited.insert(current->left);
                }

                if (current->right && visited.find(current->right) == visited.end()) {
                    nodes.push(current->right);
                    visited.insert(current->right);
                }

                if (parentTrack[current] && visited.find(parentTrack[current]) == visited.end()) {
                    nodes.push(parentTrack[current]);
                    visited.insert(parentTrack[current]);
                }
            }

            currentLevel++;  // Increment the level here
        }

        // Extract nodes at the required distance from the target
        vector<int> result;
        while (!nodes.empty()) {
            TreeNode* current = nodes.front();
            nodes.pop();
            result.push_back(current->val);
        }

        return result;
    }
};


// Time Complexity: O(N + k)
// Space Complexity: O(N)
// Where N is the number of nodes in the binary tree and k is the distance you're searching for.