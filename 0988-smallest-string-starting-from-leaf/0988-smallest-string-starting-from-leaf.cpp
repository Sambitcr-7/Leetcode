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
public:
    string smallestFromLeaf(TreeNode* root) {
        return dfs(root, "");
    }

    string dfs(TreeNode* node, std::string str) {

        str = char('a' + node->val) + str;

        if (!node->left && !node->right) {
            return str;
        } else if (!node->left) {
            return dfs(node->right, str);
        } else if (!node->right) {
            return dfs(node->left, str);
        } else {
            std::string str1 = dfs(node->left, str);
            std::string str2 = dfs(node->right, str);
            if (str1 > str2) {
                return str2;
            } else {
                return str1;
            }
        }
    }

};