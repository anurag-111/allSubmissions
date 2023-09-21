// https://leetcode.com/problems/serialize-and-deserialize-binary-tree

class Codec {
private:
    int index;
    stringstream doSerialize(TreeNode* root) {
        if(root == NULL) {
            return stringstream("X");
        }

        stringstream left = doSerialize(root -> left);
        stringstream right = doSerialize(root -> right);

        stringstream serialTree;
        serialTree << root -> val << "," << left.str() << "," << right.str();
        
        return serialTree;
    }

    TreeNode* doDeserialize(vector<string> treeData) {
        if(index == treeData.size() || treeData[index] == "X") {
            index++;
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(treeData[index]));
        index++;
        node -> left =  doDeserialize(treeData);
        node -> right = doDeserialize(treeData);

        return node;
    }

    vector<string> split(string data, char delimeter) {
        stringstream ss(data);        
        vector<string> tokens;
        string token;

        while(getline(ss, token, delimeter)) {
            tokens.push_back(token);
        }

        return tokens;        
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return doSerialize(root).str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> treeData = split(data, ',');

        index = 0;
        TreeNode* root = doDeserialize(treeData);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));