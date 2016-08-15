//最简单的思路，左右子树变链表后插入
class Solution {
public:
    void flatten(TreeNode * root){
        if(!root) return;
        flatten(root->left);
        flatten(root->right);
        
        if(!root->left) return;
        TreeNode *p=root->left;
        while(p->right) p=p->right;
        p->right = root->right;
        root->right = root->left;
        root->left = nullptr;
    }
};
//递归
class Solution {
public:
    void flatten(TreeNode *root){
        flatten(root,nullptr);
    }
private:
    static TreeNode* flatten(TreeNode *p,TreeNode *tail){//返回p为头，tail为尾的链表
        if(!p) return tail;
        p->right = flatten(p->left,flatten(p->right,tail));
        p->left = nullptr;
        return p;
    }
};
//先序遍历变体
class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode *> s;
        if(!root) return;
        s.push(root);
        while(!s.empty()){
            auto p = s.top();
            s.pop();
            if(p->right) s.push(p->right);
            if(p->left) s.push(p->left);
            p->left = nullptr;
            if(!s.empty()){
                p->right = s.top();
            }
        }
    }
};

