class Solution {
public:
    int minChanges(string s) {
        int length=s.length();
        char curr=s[0];
        int count=0;
        int change=0;
        for(int i=0;i<length;i++){
            if(s[i]==curr){
                count++;
                continue;
            }
            if(count%2==0){
                curr=s[i];
                count=1;
            }
            else{
                change++;
                count=0;
            }
        }
        return change;
    }
};