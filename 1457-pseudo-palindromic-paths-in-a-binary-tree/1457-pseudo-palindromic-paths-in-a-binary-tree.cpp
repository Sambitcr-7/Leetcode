class Solution {
private:
    int cnt=0;

    void preorder(TreeNode * root,int path){
        if(!root) return ;

        path = path^(1<<root->val);

        if(!root->left && !root->right){
            if((path & (path-1))==0) cnt++;
        }
        preorder(root->left,path);
        preorder(root->right,path);
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        preorder(root,0);
        return cnt;
    }
};