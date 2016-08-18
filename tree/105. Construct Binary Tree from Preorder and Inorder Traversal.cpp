//递归，比较慢。
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(0,preorder.size()-1,preorder,0,inorder.size()-1,inorder);
    }
private:
    static TreeNode* build(int lpre,int rpre,const vector<int>& preorder,
                           int lin,int rin,const vector<int>& inorder) {
        if(preorder.size()==0&&inorder.size()==0) return nullptr;
        int val = preorder[lpre];
        TreeNode* root = new TreeNode(val);
        int left_len = find(val,inorder)-lin;//左子树中序序列长度
        int right_len = rin-find(val,inorder);//右子树中序序列长度
        if(left_len!=0){
            root->left = build(lpre+1,lpre+left_len,preorder,lin,lin+left_len-1,inorder);
        }
        if(right_len!=0){
            root->right = build(rpre-right_len+1,rpre,preorder,rin-right_len+1, rin,inorder);
        }
        return root;
    }
    static int find(int val,const vector<int>& v){
        for(int i=0;i<v.size();++i){
            if(v[i]==val)
                return i;
        }
        return -1;
    }
};
//栈
/*
输入：前序[1,2,4,5,6,3]，中序[4，2，6，5，1，3]，过程如下：
 s.push(1)
 i=1
 1->left=2,s.push(2)
 
 i=2
 2->left=4,s.push(4)
 
 i=3
 idx=1,s.pop(4)
 idx=2,s.pop(2)
 2->right=5,s.push(5)
 
 i=4
 5->left=6,s.push(6)
 
 i=5
 idx=3,s.pop(6)
 idx=4,s.pop(5)
 idx=5,s.pop(1)
 1->right=3,s.push(3)
 
 i=6
 idx=6,s.pop(3)
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size()) return nullptr;
        stack<TreeNode*> s;
        TreeNode* root = new TreeNode(preorder[0]);
        s.push(root);cout<<"s.push("<<root->val<<")"<<endl;
        int idx = 0;
        for(int i=1;i<=preorder.size();++i){
            cout<<"i="<<i<<endl;
            TreeNode* p = s.top();
            if(p->val != inorder[idx]){
                p->left = new TreeNode(preorder[i]);
                s.push(p->left);
                cout<<p->val<<"->left="<<p->left->val<<",s.push("<<p->left->val<<")"<<endl;
            }else{
                while(!s.empty()&&s.top()->val==inorder[idx]){
                    p=s.top();
                    idx++;
                    cout<<"index="<<idx<<",s.pop("<<s.top()->val<<")"<<endl;
                    s.pop();
                }
                if(idx<inorder.size()){
                    p->right = new TreeNode(preorder[i]);
                    cout<<p->val<<"->right="<<preorder[i]<<",s.push("<<preorder[i]<<")"<<endl;
                    s.push(p->right);
                }
            }
            cout<<endl;
        }
        return root;
    }
};