class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1=INT_MIN,hold2=INT_MIN;
        int release1=0,release2=0;
        for(auto price:prices){
            if(-price>hold1){//价格比之前小，买
                hold1=-price;
            }else{//价格比之前大，卖
                release1=max(release1,price+hold1);
            }
            if(release1-price>hold2){
                hold2=release1-price;
            }else{
                release2=max(release2,price+hold2);
            }
        }
        return release2;
    }
};
