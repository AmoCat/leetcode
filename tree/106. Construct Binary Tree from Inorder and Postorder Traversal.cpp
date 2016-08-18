//右儿子的inpreorder和postorder顺序相反，左儿子的inpreorder和postorder顺序相反相同
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(postorder.back());
        stack<TreeNode*> s;
        s.push(root);
        int idx = int(inorder.size()-1);
        for(int i= int(postorder.size()-2);i>=0;--i){
            TreeNode *p=s.top();
            if(inorder[idx]!=s.top()->val){//有右儿子或右子树未遍历完
                p->right = new TreeNode(postorder[i]);
                s.push(p->right);
            }else{//右子树遍历完
                while(!s.empty()&&s.top()->val==inorder[idx]){
                    p = s.top();
                    s.pop();
                    --idx;
                }
                if(idx>=0){
                    p->left = new TreeNode(postorder[i]);
                    s.push(p->left);
                }
            }
        }
        return root;
    }
};