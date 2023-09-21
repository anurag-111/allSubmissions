// https://leetcode.com/problems/serialize-and-deserialize-binary-tree

class Codec {
private:
    int index;
    string doSerialize(TreeNode* root) {
        if (root == NULL) {
            return "X";
        }

        string left = doSerialize(root->left);
        string right = doSerialize(root->right);

        string serialTree = to_string(root->val) + "," + left + "," + right;

        return serialTree;
    }

    TreeNode* doDeserialize(vector<string>& treeData) {
        if (index == treeData.size() || treeData[index] == "X") {
            index++;
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(treeData[index]));
        index++;
        node->left = doDeserialize(treeData);
        node->right = doDeserialize(treeData);

        return node;
    }

    static vector<string> split(const string& data, char delimiter) {
        stringstream ss(data);
        vector<string> tokens;
        string token;

        while (getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }

        return tokens;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return doSerialize(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> treeData = split(data, ',');

        index = 0;
        return doDeserialize(treeData);
    }
};
