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
    int findBottomLeftValue(TreeNode* root) {
         queue<TreeNode*> q;
        q.push(root);
        int leftmostValue;

        while(!q.empty()) {

            TreeNode* frontNode = q.front();
            q.pop();

            leftmostValue = frontNode->val;

            if(frontNode->right != NULL) {
                q.push(frontNode->right);
            }
            if(frontNode->left != NULL) {
                q.push(frontNode->left);
            }
        }
        return leftmostValue;
    }
};