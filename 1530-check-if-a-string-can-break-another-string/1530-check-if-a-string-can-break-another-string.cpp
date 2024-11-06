class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int flag1=0;
        int flag2=0;
        int l1=s1.length();
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        for(int i=0;i<l1;i++){
            if(s1[i]>s2[i]){
                flag1++;
            }
            else if(s1[i]<s2[i]){
                flag2++;
            }
            else{
                flag1++;
                flag2++;
            }
        }
        if(flag1==l1||flag2==l1){
            return true;
        }
        return false;
    }
};