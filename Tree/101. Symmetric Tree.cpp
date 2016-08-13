class Solution{
public:
    bool isSymmetric(TreeNode *root){
        if(!root) return true;
        return isSymmetric(root->left,root->right);
    }
private:
    bool isSymmetric(TreeNode *p,TreeNode *q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        return isSymmetric(p->left,q->right)&&isSymmetric(p->right,q->left);//与Same Tree 唯一区别
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return symmetric(root->left,root->right);
    }
private:
    static bool symmetric(TreeNode *p,TreeNode *q){
        queue<TreeNode *> qq;
        qq.push(p);
        qq.push(q);
        while(!qq.empty()){
            p = qq.front();qq.pop();
            q = qq.front();qq.pop();
            if(!p && !q) continue;
            if(!p || !q) return false;
            if(p->val != q->val) return false;
            qq.push(p->left);//左右子树对称相等,只需把左右儿子入队列顺序换下
            qq.push(q->right);
            qq.push(p->right);
            qq.push(q->left);
        }
        return true;
    }
};
