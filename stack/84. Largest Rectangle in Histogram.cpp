class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int res=0;
        for(int i=0;i<heights.size();){
            if(!s.empty()&&heights[i]<=heights[s.top()]){
                int h = heights[s.top()];
                s.pop();
                res = max(res,h*(s.empty()?i:(i-s.top()-1)));
            }else{
                s.push(i++);
            }
        }
        return res;
        
    }
};