class Solution {
public:
    string toHex(int num) {
        if(num==0) return "0";
        int x = 0x000f;
        string res="";
        while(num!=0){
            res = hash(num&x)+res;
            num=(num>>4)&0x0fffffff;
        }
        return res;
    }
private:
    char hash(int x){
        if(x<10) {return '0'+x;}
        else return 'a'+x-10;
    }
};
