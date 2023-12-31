class Solution {
public:
    void recTraverse(TreeNode *node, string s, vector<string> &result) {

        if (node != nullptr) {

            if (s == "") s += to_string(node->val);
            else s += ("->" + to_string(node->val));

            // add string to result if current node is a leaf
            if (node->left == nullptr && node->right == nullptr) result.emplace_back(s);

            if (node->left) recTraverse(node->left, s, result);
            if (node->right) recTraverse(node->right, s, result);
        }
    } 

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;

        recTraverse(root, "", result);

        return result;
    }
};