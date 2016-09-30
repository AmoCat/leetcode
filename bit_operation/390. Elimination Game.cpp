//recursive
class Solution {
public:
    int lastRemaining(int n) {
        return recursion(n,true);
    }
private:
    int recursion(int n,bool isLeft){
        if(n==1) return 1;
        if(!isLeft&&n%2==0){
            return recursion(n/2, !isLeft)*2-1;
        }else{
            return recursion(n/2, !isLeft)*2;
        }
    }
};
//