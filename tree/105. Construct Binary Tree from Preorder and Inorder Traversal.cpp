//递归，比较慢。
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size()&&inorder.size()) return nullptr;
        int len=preorder.size();
        return construct(preorder.begin(),inorder.begin(),len);
    }
private:
    TreeNode* construct(vector<int>::iterator preorder,vector<int>::iterator inorder,int len) {
        if(len<=0) return nullptr;
        TreeNode* root = new TreeNode(*preorder);
        if(len == 1) return root;
        for(int i=0;i<len;++i){
            if((*(inorder+i))==(*preorder)){
                int lchild_len = i;
                int rchild_len = len-i-1;
                root->left = construct(preorder+1, inorder, lchild_len);
                root->right = construct(preorder+i+1, inorder+i+1, rchild_len);
            }
        }
        return root;
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