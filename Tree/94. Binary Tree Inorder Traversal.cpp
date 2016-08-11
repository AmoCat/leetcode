
//中序Morris
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        vector<int> res;
        while(cur!=nullptr){
            if(cur->left==nullptr){
                res.push_back(cur->val);
                pre=cur;
                cur=cur->right;
            }else{
                TreeNode *p = cur->left;
                while(p->right !=nullptr && p->right != cur)
                    p=p->right;
                if(p->right == nullptr){//第一次遍历到cur
                    p->right=cur;
                    cur=cur->left;
                }else{//第二次
                    res.push_back(cur->val);
                    p->right = nullptr;
                    cur=cur->right;
                }
            }
        }
        return res;
    }
};
//死循环，23多次加入栈.用p作s.top又用p做移动变量的方法不可行。
class Solution {
public:
    vector<int> inorderTraversal(TreeNode * root) {
        TreeNode * p;
        stack<TreeNode *> s;
        vector<int> res;
        if(root !=nullptr)
            s.push(root);
        while(!s.empty())
        {
            p=s.top();//只有查到null，需要知道父节点时才用s.top，否则死循环
            if(p->left!=nullptr){
                s.push(p->left);
            }else{
                res.push_back(p->val);
                s.pop();
                if(p->right!=nullptr)
                    s.push(p->right);
            }
        }
        return res;
    }
};
//正解
class Solution {
public:
    vector<int> inorderTraversal(TreeNode * root) {
        TreeNode * p=root;
        stack<TreeNode *> s;
        vector<int> res;
        while(!s.empty()||p!=nullptr){
            if(p!=nullptr){
                s.push(p);
                p=p->left;
            }else{
                p=s.top();
                s.pop();
                res.push_back(p->val);
                p=p->right;
            }
        }
        return res;
        
    }
};
