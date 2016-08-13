//或Binary Tree Level Order Traversal 基础上直接std:reverse
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        traverse(root,1,res);
        reverse(res);
        return res;
        
    }
private:
    static void traverse(TreeNode *p,int level,vector<vector<int>> &res){
        if(!p) return;
        if(level>res.size()){
            res.push_back(vector<int>());
        }
        res[level-1].push_back(p->val);
        traverse(p->left,level+1,res);
        traverse(p->right,level+1,res);
        
    }
    static void reverse(vector<vector<int>> &res){
        stack<vector<int>> s;
        vector<vector<int>>::iterator it;
        for(it=res.begin();it!=res.end();it++)
            s.push(*it);
        res.clear();
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
    }
};