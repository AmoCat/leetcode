class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        getPath(root,"",res);
        return res;
    }
private:
    static void getPath(TreeNode* rt,string path,vector<string> &res){
        if(!rt) return;
        stringstream ss;
        string val;
        ss << rt->val;
        ss >> val;
        if(!rt->left&&!rt->right) {res.push_back(path+val);return;}
        if(rt->left) getPath(rt->left, path+val+"->", res);
        if(rt->right) getPath(rt->right, path+val+"->", res);
    }
};