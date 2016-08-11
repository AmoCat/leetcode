class Solution{
public:
    vector<int> postorderTraversal(TreeNode * root){
        TreeNode *p=root;
        vector<int> res;
        stack<TreeNode *> s;
        while(p){
            s.push(p);
            p=p->left;
        }//���������׶�
        TreeNode * last = nullptr;
        while(!s.empty()){
            p=s.top();
            s.pop();
            if(p->right==nullptr || p->right == last){//�����������������ձ�����
                res.push_back(p->val);
                last = p;
            }else{
                s.push(p);
                p=p->right;
                while(p){
                    s.push(p);
                    p=p->left;
                }
            }
        }
        return res;
    }
};