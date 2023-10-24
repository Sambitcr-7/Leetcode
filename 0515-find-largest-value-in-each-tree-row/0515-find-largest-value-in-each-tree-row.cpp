class Solution {
public:

    vector <int> res;
    void traverse(TreeNode* root, int currlevel, int &maxlevel){
        if(!root) return;
        if(currlevel > maxlevel){ // new level
            maxlevel = currlevel; //update maxlevel
            res.push_back(root->val); //add value to vector
        }
        //otherwise level already visited (entry in vector exists)
        res[currlevel] = max(res[currlevel], root->val); 
        //update value in vector
        traverse(root->left, currlevel+1, maxlevel); //recurse
        traverse(root->right, currlevel+1, maxlevel);
    }
    vector<int> largestValues(TreeNode* root) {
        res.clear();
        int maxlevel = -1;
        traverse(root, 0, maxlevel);
        return res;
    }
};