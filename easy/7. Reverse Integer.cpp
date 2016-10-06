class Solution {
public:
    int reverse(int x) {
        long res = 0;
        for(; x!=0 ; x /= 10) { res = res*10 + x%10; }
        return (res > INT_MAX || res < INT_MIN) ? 0 : res;
    }
};
