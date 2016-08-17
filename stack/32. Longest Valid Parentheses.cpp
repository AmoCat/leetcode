//栈内存下标
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int last = -1;
        int maxn = 0;
        for(int i=0;i<s.size();++i){
            if(s[i]==')'){
                if(stk.empty()){
                    last = i;
                }else{
                    stk.pop();
                    if(stk.empty()){
                        maxn = max(maxn,i-last);
                    }else{
                        maxn = max(maxn,i-stk.top());
                    }
                }
            }else{
                stk.push(i);
            }
        }
        return maxn;
    }
};