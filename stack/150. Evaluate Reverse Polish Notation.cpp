class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto s:tokens){
            if(!isOperator(s)){
                stk.push(stk.push(stoi(s)));
            }else{
                a = stk.top();
                stk.pop();
                b = stk.top();
                stk.pop();
                if(s[0]=='+') stk.push(b+a);
                if(s[0]=='-') stk.push(b-a);
                if(s[0]=='*') stk.push(b*a);
                if(s[0]=='/') stk.push(b/a);
            }
        }
        return stk.top();
    }
private:
    bool isOperator(const string &s) {
        return s.size()==1&&string("+-*/").find(s)!=std:npos;
    }
};