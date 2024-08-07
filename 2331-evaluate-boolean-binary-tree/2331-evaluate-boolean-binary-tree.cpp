
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root == nullptr)return false;

        switch(root->val){
            case 0:
            case 1:
                return root->val;
            case 2:
                return evaluateTree(root->right) || evaluateTree(root->left);
            case 3:
                return evaluateTree(root->right) && evaluateTree(root->left);
        }
        return false;
    }
};