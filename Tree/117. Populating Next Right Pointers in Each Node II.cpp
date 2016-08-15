//本题解法均可解决Populating Next Right Pointers in Each Node
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
//题解中的递归解法
//pre相当于层序遍历的上个节点。在第二层开始的每层建立了一个节点dummy，指向每层最左的节点。通过dummy.next找到下层第一个节点
class Solution {
public:
    void connect(TreeLinkNode *root){
        if(!root) return;
        TreeLinkNode dummy(-1);
        for(TreeLinkNode *cur = root,*pre = &dummy;cur; cur = cur->next){
            if(cur->left != nullptr) {
                pre->next = cur->left;
                pre = pre->next;
            }
            if(cur->right != nullptr) {
                pre->next = cur->right;
                pre = pre->next;
            }
        }
        connect(dummy.next);
    }
};
class Solution {
public:
    void connect(TreeLinkNode *root){
        TreeLinkNode *p = root;
        while(p){
            TreeLinkNode *next = nullptr;//下层第一个节点
            TreeLinkNode *pre = nullptr;//本层前一个遍历到的节点
            for(;p;p=p->next){
                if(!next) next = p->left?p->left:p->right;//找到下层第一个节点。
                if(p->left){
                    if(pre) pre->next = p->left;
                    pre=p->left;
                }
                if(p->right){
                    if(pre) pre->next = p->right;
                    pre=p->right;
                }
            }
            p=next;
        }
    }
};
