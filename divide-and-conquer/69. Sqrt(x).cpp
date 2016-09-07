class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        int l=1,r=x/2,last_mid;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(x/mid>mid){
                l=mid+1;
                last_mid=mid;
            }else if(x/mid<mid){
                r=mid-1;
            }else{
                return mid;
            }
        }
        return last_mid;
    }
};
