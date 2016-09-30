class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if(matrix.size()==0) return 0;
        vector<vector<int> > lar;
        for(auto v:matrix){
            vector<int> vec;
            for(char c:v) vec.push_back(c=='0'?0:1);
            lar.push_back(vec);
        }
        int maxn=0;
        for(int x:lar.front()) maxn=max(maxn,x);
        if(matrix.size()==1) return maxn;
        for(int i=1;i<lar.size();++i){
            for(int j=1;j<lar.front().size();++j){
                if(lar[i][j]==0) continue;
                if(lar[i-1][j-1]>0&&lar[i-1][j]>0&&lar[i][j-1]>0){
                    lar[i][j]=1+getMin(lar[i-1][j-1],lar[i-1][j],lar[i][j-1]);
                }
                maxn=max(maxn,lar[i][j]);
            }
        }
        return maxn*maxn;
    }
private:
    int getMin(int a,int b,int c){
        return min(min(a,b),c);
    }
};