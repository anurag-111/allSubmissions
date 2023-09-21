// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

class Solution {
private:
	void childParentMapper(TreeNode *root, unordered_map<TreeNode *, TreeNode*> &childParentMap, TreeNode *target) {
		// Node storage
		queue<TreeNode*> nodes;
		nodes.push(root);
		
		while(!nodes.empty()) {
			int size = nodes.size();
			
			for(int i = 0; i < size; i++) {
				TreeNode *current = nodes.front();
				nodes.pop();
				
				if(current -> left) {
					nodes.push(current -> left);
					childParentMap[current -> left] = current;
				}
				
				if(current -> right) {
					nodes.push(current -> right);
					childParentMap[current -> right] = current;
				}				
			}
		}
	}
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // For mapping
		unordered_map<TreeNode*, TreeNode*> childParentMap;
		
		// Function for mapping
		childParentMapper(root, childParentMap, target);
		
		// Node storage
		queue<TreeNode*> nodes;
		nodes.push(target);
		
		// Level indicator
		int currentLevel = 0;
		
		// Visited mapping
		unordered_set<TreeNode*> visited;
		visited.insert(target);
		
		while(!nodes.empty()) {
			int size = nodes.size();
			
			// Current level check
			if(currentLevel == k) {
				break;
			}
			
			//  Traversing over the loop
			for(int i = 0; i < size; i++) {
				// Extraction of nodes
				TreeNode *current = nodes.front();
				nodes.pop();
				
				// Left traversal nodes
				if(current -> left && visited.find(current -> left) == visited.end()) {
					nodes.push(current -> left);
					visited.insert(current -> left);
				}
				
				// Right traversal nodes
				if(current -> right && visited.find(current -> right) == visited.end()) {
					nodes.push(current -> right);
					visited.insert(current -> right);
				}
				
				// Parent node
				if(childParentMap[current] && visited.find(childParentMap[current]) == visited.end()) {
					nodes.push(childParentMap[current]);
					visited.insert(childParentMap[current]);
				}				
			}
			
			// Update the current level
			currentLevel++;
		}
		
		// For storing the resultant node's value
		vector<int> result;
		
		// Pop the required nodes
		while(!nodes.empty()) {
			TreeNode *current = nodes.front();
			nodes.pop();
			// Add the nodes
			result.push_back(current -> val);
		}
		
		return result;
    }
};