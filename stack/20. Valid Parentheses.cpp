class Solution {
public:
    bool isValid(string s) {
        string left = "([{";
        string right = ")]}";
        stack<char> stk;
        for(auto c:s){
            if(left.find(c)!=string::npos)
                stk.push(c);
            else {
                if(stk.empty()||left[right.find(c)]!=stk.top())
                    return false;
                else stk.pop();
            }
        }
        return stk.empty();
    }
};