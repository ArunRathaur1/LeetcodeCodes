class Solution {
public:
    string reverseWords(string s) {
        int left=0;
        int right=0;
        int l=s.length();
        string ans="";
        reverse(s.begin(),s.end());
        while(s[l-1]==' '){
            l--;
        }
        while(right<l){
            if(s[right]==' '){
                right++;
            }
            else{
                left=right;
                while(right<l&&s[right]!=' '){
                    right++;
                }
                int temleft=left;
                int temright=right-1;
                while(temleft<temright){
                    swap(s[temleft],s[temright]);
                    temleft++;
                    temright--;
                }
                for(int i=left;i<right;i++){
                    ans+=s[i];
                }
                if(right==l){
                    continue;
                }
                ans+=" ";
            }
        }
        return ans;
    }
};