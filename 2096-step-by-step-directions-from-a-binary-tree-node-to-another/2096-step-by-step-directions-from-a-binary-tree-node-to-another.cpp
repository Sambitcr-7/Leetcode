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
    bool getPath(TreeNode *node, const int &target, string &path) {
        if (node == nullptr) 
            return false;

        if (node->val == target)
            return true;

        // Check left side, if not found, pop the step
        path += "L";
        bool left = getPath(node->left, target, path);
        if (!left) {
            path.pop_back(); 
        }

        // Check right side, if not found, pop the step
        path += "R";
        bool right = getPath(node->right, target, path);
        if (!right) {
            path.pop_back();
        }

        return left || right;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string p_to_start, p_to_dest;
        // Get the path from root to start node and end node
        getPath(root, startValue, p_to_start);
        getPath(root, destValue, p_to_dest);

        int depth = 0;
        int n_start = p_to_start.length();
        int n_dest = p_to_dest.length();

        // Find the common node depth
        while (depth < n_start && depth < n_dest) {
            if (p_to_start[depth] != p_to_dest[depth]) {
                break;
            }
            ++depth;
        }

        // Get final path
        string result(n_start - depth, 'U');
        while (depth < n_dest) {
            result += p_to_dest[depth++];
        }

        return result;
    }
};
