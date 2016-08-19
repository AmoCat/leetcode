class Solution {
public:
    int jump(vector<int>& nums) {
        int step=0;
        int left=0,right=0;
        if(nums.size()<=1) return 0;
        while(left<=right){
            ++step;
            int old_right = right;
            for(int i = left;i<=old_right;++i){
                right = max(right,i+nums[i]);
                if(right>=nums.size()-1) return step;
            }
            left = old_right+1;
        }
        return 0;
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        int res=0;
        int last=0;
        int cur=0;
        for(int i=0;i<nums.size();++i){
            if (i > last) {//跳出了原来走的最大区间，则步数加1
                last = cur;
                ++res;
            }
            cur = max(cur, i + nums[i]);
        }
        return res;
    }
};