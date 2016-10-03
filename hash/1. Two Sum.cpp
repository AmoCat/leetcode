class Solution{
public:
    vector<int> twoSum(vector<int> &nums,int targets){
        int i=0;
        vector<int> res;
        vector<pair<int,int>> tmp;
        for(auto x:nums){ tmp.push_back(make_pair(x, i++)); }
        sort(tmp.begin(), tmp.end(),compare);
        for(int i=0,j=tmp.size()-1;i<j;){
            int x = tmp[i].first+tmp[j].first;
            if(x==targets){
                res.push_back(tmp[i].second);
                res.push_back(tmp[j].second);
                return res;
            }else if(x<targets){
                ++i;
            }else{
                --j;
            }
        }
        return res;
    }
private:
    static bool compare(pair<int, int> a,pair<int, int> b){
        return a.first<b.first;
    }
};
class Solution{
public:
    vector<int> twoSum(vector<int> &nums,int targets){
        unordered_map<int, int> hash;
        vector<int> res(2,0);
        for(int i=0;i<nums.size();++i){
            if(hash.find(targets-nums[i])!=hash.end()){
                int j = hash[targets-nums[i]];
                res[0]=i<j?i:j;
                res[1]=i>j?i:j;
            }
            hash[nums[i]]=i;
        }
        return res;
    }
};
