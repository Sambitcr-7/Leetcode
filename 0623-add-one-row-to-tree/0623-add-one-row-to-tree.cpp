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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
         if (depth == 1) {
            return new TreeNode(val, root, nullptr);  
        }

        queue<TreeNode*>q;
        q.push(root);
        int level =0;
        while(!q.empty()){
            level++;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(level == depth-1){
                   TreeNode* new_left = new TreeNode(val);
                   TreeNode* new_right = new TreeNode(val);
                   TreeNode* og_left = node->left;
                   TreeNode* og_right = node->right;
                   node->left = new_left;
                   node->right = new_right;
                   node->left->left = og_left;
                   node->right->right = og_right; 
                }
                else{
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
        }
        return root;
    }
};