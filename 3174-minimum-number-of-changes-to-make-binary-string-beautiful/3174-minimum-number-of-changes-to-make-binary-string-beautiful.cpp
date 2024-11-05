class Solution {
public:
    int minChanges(string s) {
        int length=s.length();
        char curr=s[0];
        int count=0;
        int change=0;
       int i=0;
        while(i<length){
            if(s[i]==curr){
                count++;
            }
            else {
                if(count%2!=0){
                    s[i]=curr;
                    change++;
                    if(i+1<length){
                        curr=s[++i];
                    }
                }
                else{
                    curr=s[i];
                } 
                count=1;
            }
            i++;
        }
        // if(count%2!=0){
        //     count++;
        // }
        return change;
    }
};