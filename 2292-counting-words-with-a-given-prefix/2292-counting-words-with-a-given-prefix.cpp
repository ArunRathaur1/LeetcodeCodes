class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        int x=pref.length();
        for(auto word : words){
            if(word.length()<x)continue;
            int y=0;
            int flag=0;
            for(auto ch:pref){
                if(ch==word[y]){
                    y++;
                }
                else{
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                count++;
            }
        }
        return count;
    }
};