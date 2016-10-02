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
/*In fact, we can prove that "ML(1...n) + MR(1...n) = 1 + n" holds for any n >= 2, where ML(1...n) means removing elements from left to right first and MR(1...n) means removing elements from right to left first.
lastRemaining(n) + EliminateFromRightFirst(n) = n + 1;
<=> lastRemaining(n/2) + EliminateFromRightFirst(n/2) = n/2 + 1;
<=> EliminateFromRightFirst(n/2) = 1 + n/2 - lastRemaining(n/2);*/
int lastRemaining(int n) {
    return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
}
//