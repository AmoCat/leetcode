class Solution{
public:
    vector<int> postorderTraversal(TreeNode * root){
        TreeNode *p=root;
        vector<int> res;
        stack<TreeNode *> s;
        while(p){
            s.push(p);
            p=p->left;
        }
        TreeNode * last = nullptr;
        while(!s.empty()){
            p=s.top();
            s.pop();
            if(p->right==nullptr || p->right == last){//无子树或左子树刚被访问
                res.push_back(p->val);
                last = p;
            }else{
                s.push(p);
                p=p->right;
                while(p){
                    s.push(p);
                    p=p->left;
                }
            }
        }
        return res;
    }
};

//Morris
class Solution {
public:
    vector<int> postorderTraversal(TreeNode * root){
        vector<int> res;
        TreeNode dummy(-1);
        dummy.left = root;
        TreeNode *cur=&dummy,*prev =nullptr;
        std::function< void(const TreeNode*)>  visit=[&res](const TreeNode *node){res.push_back(node->val);};
        //lamda表达式，[&res]按引用访问res，《primer plus 》p821
        
        while(cur != nullptr){
            if(cur->left == nullptr){//访问右子树的条件是左子树为空或左子树访问完了
                prev = cur;
                cur = cur -> right;
            }else{
                TreeNode *p = cur->left;
                while(p->right != nullptr && p->right != cur){
                    p=p->right;
                }
                
                if(p->right == nullptr){//第一次访问到cur，线索化并遍历左子树
                    p->right = cur;
                    prev = cur;
                    cur = cur->left;
                }else{
                    visit_reverse(cur->left,prev,visit);//倒序输出前驱节点到当前节点左儿子路径上的所有节点
                    prev->right = nullptr;
                    prev = cur;
                    cur = cur -> right;
                }
            }
        }
        return res;
    }
private:
    static void reverse(TreeNode *from, TreeNode *to){
        TreeNode *x=from,*y=from->right,*z=nullptr;
        if(from == to )
            return;
        while(x!=to){//右儿子链表倒置
            z=y->right;
            y->right=x;
            x=y;
            y=z;
        }
    }
    static void visit_reverse(TreeNode *from,TreeNode *to,std::function <void(const TreeNode *)>& visit){
        TreeNode *p = to;
        reverse(from,to);
        while(true){
            visit(p);
            if(p==from)
                break;
            p=p->right;
        }
        reverse(to,from);
    }
};
