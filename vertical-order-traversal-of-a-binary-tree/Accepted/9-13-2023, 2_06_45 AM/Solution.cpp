// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> verticalMap; // Map to store nodes at each vertical position.

        // Use a queue for level-order traversal along with row and column positions.
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            int size = q.size();
            map<int, vector<pair<int, int>>> temp; // Temporary map for this level.

            // Process nodes at this level.
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front().first;
                int row = q.front().second.first;
                int col = q.front().second.second;
                q.pop();

                temp[col].push_back({row, node->val}); // Store node's row and value.

                if (node->left)
                    q.push({node->left, {row + 1, col - 1}});

                if (node->right)
                    q.push({node->right, {row + 1, col + 1}});
            }

            // Merge the temporary map into the main vertical map.
            for (const auto& entry : temp) {
                vector<pair<int, int>> nodes = entry.second;
                sort(nodes.begin(), nodes.end()); // Sort nodes in the same column by their row.

                for (auto pair : nodes) {
                    verticalMap[entry.first].push_back(pair); // Add pairs to the main map.
                }
            }
        }

        vector<vector<int>> result;

        // Extract the vertical order traversal from the map.
        for (const auto& entry : verticalMap) {
            vector<int> columnValues; // To store values in the current column.
            for (const auto& pair : entry.second) {
                columnValues.push_back(pair.second); // Extract the values.
            }
            result.push_back(columnValues); // Add the column's values to the result.
        }

        return result;
    }
};
