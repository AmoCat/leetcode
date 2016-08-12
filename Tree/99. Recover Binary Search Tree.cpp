//同普通Morris不同唯一不同在于visit的地方换成了detect，然后交换
class Solution {
public:
    void recoverTree(TreeNode *root){
        TreeNode *cur=root,*prev=nullptr;
        pair<TreeNode *,TreeNode *> broken;
        while(cur != nullptr){
            if(cur->left == nullptr){
                detect(broken,prev,cur);
                prev = cur;
                cur = cur->right;
            }else{
                TreeNode *p = cur -> left;
                while(p->right != nullptr && p->right != cur){
                    p=p->right;
                }
                if(p->right == nullptr){
                    p->right = cur;
                    cur = cur -> left;
                }else{
                    detect(broken,prev,cur);
                    p->right = nullptr;
                    prev = cur;
                    cur = cur->right;
                }
            }
        }
        swap(broken.first->val,broken.second->val);
    }
private:
    void detect(pair<TreeNode *,TreeNode *>& broken,TreeNode *prev, TreeNode *cur){
        if(prev !=nullptr && prev->val > cur->val){
            if(broken.first == nullptr){//必须if，否则[2,3,1]会输出WA[2,3,1],正确答案为[2,1,3]
                broken.first = prev;
            }
            broken.second = cur;
        }
    }
};
