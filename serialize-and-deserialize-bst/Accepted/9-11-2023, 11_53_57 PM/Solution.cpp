// https://leetcode.com/problems/serialize-and-deserialize-bst

class Codec {
public:
    // Serialize the binary tree to a string in Preorder traversal
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "null"; // Represent null nodes as "null"
        }
        
        string left = serialize(root->left);   // Serialize the left subtree
        string right = serialize(root->right); // Serialize the right subtree
        
        return to_string(root->val) + "," + left + "," + right;
    }
    
    // Deserialize the binary tree from a serialized string
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserializeHelper(iss);
    }
    
    // Deserialize helper function
    TreeNode* deserializeHelper(istringstream& iss) {
        string val;
        getline(iss, val, ','); // Read the next value
        
        if (val == "null") {
            return nullptr; // Return nullptr for "null" nodes
        }
        
        TreeNode* root = new TreeNode(stoi(val)); // Create a new node with the value
        
        root->left = deserializeHelper(iss);  // Deserialize the left subtree
        root->right = deserializeHelper(iss); // Deserialize the right subtree
        
        return root;
    }
};
