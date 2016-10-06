class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxn = INT_MIN,cur_max = 0;
        for(int i = 0; i < nums.size(); ++i){
            cur_max += nums[i];
            maxn = max(maxn,cur_max);
            if(cur_max < 0){ cur_max = 0; }
        }
        return maxn;
    }
};
