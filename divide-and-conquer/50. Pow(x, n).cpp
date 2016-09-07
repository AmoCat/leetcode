class Solution {
public:
    double myPow(double x, int n) {
        if(n<0) return 1.0/Pow(x,-n);
        return Pow(x,n);
    }
private:
    double Pow(double x,int n){
        if(n==0) return 1;
        double tmp = Pow(x,n/2);
        if(n%2==0) return tmp*tmp;
        return tmp*tmp*x;
    }
};
