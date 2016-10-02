const string HEX="0123456789abcdef";
class Solution {
public:
    string toHex(int num) {
        if(num==0) return "0";
        int x = 0xf;
        string res="";
        while(num!=0){
            res = HEX(num&x)+res;
            num=(num>>4)&0x0fffffff;
        }
        return res;
    }
};
