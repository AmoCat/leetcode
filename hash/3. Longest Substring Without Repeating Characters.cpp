class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        memset(lastIndices,-1,sizeof(lastIndices));
        int longest=0,cur_left=0,cur_l=0;
        for(int i=0;i<s.size();++i){
            if(lastIndices[s.at(i)]>=cur_left){//在目前为止的最长子串中有重复的
                cur_left=lastIndices[s.at(i)]+1;
                cur_l=i-cur_left+1;
            }else{//在cul_left~i未出现过。包括两种情况：1）之前从未出现；2）在cur_left前出现过
                ++cur_l;
            }
            lastIndices[s.at(i)]=i;
            longest=max(cur_l,longest);
        }
        return longest;
    }
private:
    int lastIndices[256];
};