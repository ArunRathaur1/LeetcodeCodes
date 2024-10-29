class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>ans(n);
        int a=0,b=0,c=0;
        ans[0]=1;
        for(int i=1;i<n;i++){
            int k1=ans[a]*2;
            int k2=ans[b]*3;
            int k3=ans[c]*5;
            int minvalue=min(k1,min(k2,k3));
            ans[i]=minvalue;
            if(k1==minvalue)a++;
             if(k2==minvalue)b++;
            if(k3==minvalue)c++;
        }
        return ans.back();
    }
};