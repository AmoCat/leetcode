class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;
        hasPathSum(root,sum,cur,res);
        return res;
    }
private:
    static void hasPathSum(TreeNode* p,int gap,vector<int>& cur,vector<vector<int>>& res){
        if(!p) return;
        cur.push_back(p->val);
        if(!p->left&&!p->right&&gap==p->val){
            res.push_back(cur);
        }
        hasPathSum(p->left,gap-p->val,cur,res);
        hasPathSum(p->right,gap-p->val,cur,res);
        cur.pop_back();
    }
};