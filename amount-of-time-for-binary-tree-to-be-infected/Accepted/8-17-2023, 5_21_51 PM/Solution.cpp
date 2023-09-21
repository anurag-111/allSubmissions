// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected

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
	private :
		TreeNode *childToParentMapper(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &childToParentMap, int target) {
			// Queue for BFS traversal
			queue<TreeNode*> nodes;
			nodes.push(root);
			
			TreeNode *targetNode = nullptr;
			
			while(!nodes.empty()) {
				int size = nodes.size();
				
				for(int i = 0; i < size; i++) {
					TreeNode* current = nodes.front();
					nodes.pop();
					
					if(current -> val == target) {
					targetNode = current;
				  }
					
					if(current -> left) {
						nodes.push(current -> left);
						childToParentMap[current -> left] = current;
					}
					
					if(current -> right) {
						nodes.push(current -> right);
						childToParentMap[current -> right] = current;
					}
				}
			}
			
			return targetNode;
		}
		
	public :
		int amountOfTime(TreeNode* root, int target) {
			// Mapping Creation
			unordered_map<TreeNode*, TreeNode*> childToParentMap;
			
			// Target value has been given to us in 'int', convert to 'TreeNode*'
			// Function call for mapping
			TreeNode *targetNode = childToParentMapper(root, childToParentMap, target);
			
			//  For visited markings
			unordered_set<TreeNode*> visited;
			
			// Queue for BFS
			queue<TreeNode*> nodes;
			nodes.push(targetNode);
			
			// Insert the visited node
			visited.insert(targetNode);
			
			// Time to burn : Initialize with -1 to account for starting from target
			int timeToBurn = -1;
			
			while(!nodes.empty()) {
				int size = nodes.size();
				
				// Level order traversal
				for(int i = 0; i < size; i++) {
					TreeNode* current = nodes.front();
					nodes.pop();
					
					
					// Left residing nodes
					if(current -> left && visited.find(current -> left) == visited.end()) {
						visited.insert(current -> left);
						nodes.push(current -> left);
					}
					
					// Right residing nodes
					if(current -> right && visited.find(current -> right) == visited.end()) {
						visited.insert(current -> right);
						nodes.push(current -> right);
					}
					
					// For parents of the current node
					if(childToParentMap[current] && visited.find(childToParentMap[current]) == visited.end()) {
						visited.insert(childToParentMap[current]);
						nodes.push(childToParentMap[current]);
					}
				}
				
				timeToBurn++;
				
 			}
			
			return timeToBurn;
		}
};

//  time complexity of O(N) and a space complexity of O(N)