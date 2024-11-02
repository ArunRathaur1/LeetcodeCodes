class Solution {
public:
    char cylinder(char ch){
        return char((int(ch-'a')+1)%26+'a');
    }
    bool canMakeSubsequence(string str1, string str2) {
        int i1=0,i2=0;
        int l1=str1.length(),l2=str2.length();
        if(l1<l2)return false;
        
        while(i2<l2&& i1<l1){
            if(str1[i1]!=str2[i2]&& cylinder(str1[i1])!=str2[i2]){
               i1++;
            }
            else{
                i1++;
                i2++;
            }
            
        }
        if(i2==l2)return true;
        return false;
    }
};