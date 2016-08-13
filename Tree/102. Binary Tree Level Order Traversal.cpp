class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        traverse(root,1,res);
        return res;
    }
    
private:
    static void traverse(TreeNode *p,int level,vector<vector<int>> & res){
        if(!p) return;
        if(res.size()<level){
            res.push_back(vector<int>());
        }
        res[level-1].push_back(p->val);//并非每个vector都填好才放入res，而是放入res后再添
        traverse(p->left,level+1,res);
        traverse(p->right,level+1,res);
    }
};
//非迭代
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {//非迭代通过两个队列记录不同Level
        vector<vector<int>> res;
        queue<TreeNode *> cur,next;
        if(!root){
            return res;
        }else{
            cur.push(root);
        }
        while(!cur.empty()){//两个while比较巧妙..
            vector<int> v;
            while(!cur.empty()){
                TreeNode *p = cur.front();
                cur.pop();
                v.push_back(p->val);
                if(p->left) next.push(p->left);
                if(p->right) next.push(p->right);
            }
            res.push_back(v);
            swap(cur,next);
        }
        return res;
    }
};
