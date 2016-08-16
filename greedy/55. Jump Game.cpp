class Solution {
public:
    bool canJump(vector<int> & nums) {
        int reach = 0;
        for(int i=0;i<=reach && reach < nums.size()-1;++i){
            reach = max(reach,i+nums[i]);
        }
        return reach>=nums.size();
    }
};
class Solution {
public:
    bool canJump(const vector<int>& nums) {
        int left_most = nums.size()-1;
        for(int i = nums.size()-2;i>=0;--i){
            if(i+nums[i]>=left_most)
                left_most = i;
        }
        return left_most <= 0;
    }
};
class Solution {
public:
    bool canJump(const vector<int>& nums) {
        if(!nums.size()) return true;
        vector<int> f(nums.size(),0);
        f[0]=nums[0];
        for(int i=1;i<nums.size();++i){
            f[i]=max(f[i-1],nums[i-1])-1;
            if(f[i]<0) return false;
        }
        return true;
    }
};
