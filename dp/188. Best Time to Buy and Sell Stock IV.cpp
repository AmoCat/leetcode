class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k>=prices.size()/2+1) {
            int res=0;
            for(int i=1;i<prices.size();++i)
                res+=max(0,prices[i]-prices[i-1]);
            return res;
        }
        vector<int> sold(k+1,INT_MIN);
        vector<int> release(k+1,0);
        for(int price:prices){
            for(int j=1;j<=k;++j){
                sold[j]=max(sold[j],release[j-1]-price);
                release[j]=max(release[j],sold[j]+price);
            }
        }
        return release[k];
    }
};