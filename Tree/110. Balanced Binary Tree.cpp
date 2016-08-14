class Solution {
public:
    bool isBalanced(TreeNode *root){
        if(!root) return true;
        int d = h(root->left)-h(root->right);
        if(!(d>=-1&&d<=1)) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
private:
    static int h(TreeNode *p){
        if(!p) return 0;
        return max(h(p->left),h(p->right))+1;
    }
};
