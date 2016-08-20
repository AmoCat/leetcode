class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left&&root->right) return 1+minDepth(root->right);
        if(!root->right&&root->left) return 1+minDepth(root->left);
        return min(minDepth(root->left),minDepth(root->right))+1;
    }
};
class Solution {
public:
    int minDepth(const TreeNode *root) {
        return minDepth(root, false);
    } private:
    static int minDepth(const TreeNode *root, bool hasbrother) {
        if (!root) return hasbrother ? INT_MAX : 0;
        return 1 + min(minDepth(root->left, root->right != NULL),
                       minDepth(root->right, root->left != NULL));
    }
};