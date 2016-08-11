//栈
public:

vector<int> preorderTraversal(TreeNode* root) {
    stack <const TreeNode *> s;
    vector <int> res;
    res.clear();
    if(root != nullptr) s.push(root);
    
    while(!s.empty()){
        const TreeNode *p = s.top();
        s.pop();
        res.push_back(p->val);
        if(p->left!=nullptr)
            s.push(p->left);
        if(p->right!=nullptr)
            s.push(p->right);
    }
    return res;
}
};
//Morris先序
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root){
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        vector<int> res;
        res.clear();
        while(cur!=nullptr){
            if(cur->left==nullptr){
                res.push_back(cur->val);
                pre=cur;
                cur=cur->right;
            }else{
                TreeNode * p=cur->left;
                while(p->right!=nullptr && p->right != cur)
                    p=p->right;
                if(p->right==nullptr){
                    p->right = cur;
                    res.push_back(cur->val);
                    pre=cur;
                    cur=cur->left;
                }else{
                    cur=cur->right;
                    p->right = nullptr;
                }
            }
        }
        return res;
    }
};