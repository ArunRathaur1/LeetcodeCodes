class Solution {
public:
    int maxScore(string s) {
        int l=s.length();
        int count_1=0;
        int count_0=0;
        for(int i=0;i<l;i++){
           if(s[i]=='1'){
            count_1++;
           }
        }
        int maxcount=0;
        for(int i=0;i<l-1;i++){
            if(s[i]=='1'){
                count_1--;
            }
            if(s[i]=='0'){
                count_0++;
            }
            maxcount=max(maxcount,count_1+count_0);
        }
        return maxcount;
    }
};