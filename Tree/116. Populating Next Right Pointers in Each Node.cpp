//与Binary Tree Level Order Traversal类似的方法，两个队列，空间复杂度O(1).
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode *> cur,next;
        TreeLinkNode * pre = nullptr;
        if(!root) return;
        cur.push(root);
        while(!cur.empty()){
            pre = nullptr;
            while(!cur.empty()){
                TreeLinkNode *p = cur.front();
                cur.pop();
                if(pre) pre->next = p;
                pre = p;
                if(p->left) next.push(p->left);//注意if，否则RE
                if(p->right) next.push(p->right);
            }
            pre->next = NULL;
            swap(cur,next);
        }
    }
};
