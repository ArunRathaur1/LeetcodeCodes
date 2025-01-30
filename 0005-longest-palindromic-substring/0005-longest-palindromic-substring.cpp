class Solution {
public:
    string longestPalindrome(string s) {
        //case;
        int n=s.length();
        int maxcount=0;
        string output="";
        for(int i=0;i<n;i++){
            int left=i-1;
            int right=i+1;
            int count=1;
            while(left>=0&& right<n){
                if(s[left]==s[right]){
                    left--;
                    right++;
                    count+=2;
                }
                else{
                    break;
                }
            }
            if(count>maxcount){
                output=s.substr(left+1,right-left-1);
                maxcount=count;
            }
        }
        for(int i=0;i<n;i++){
            if(i+1>=n)continue;
            int left=i;
            int right=i+1;
            int count=0;
            while(left>=0&& right<n){
                if(s[left]==s[right]){
                    left--;
                    right++;
                    count+=2;
                }
                else{
                    break;
                }
            }
            if(count>maxcount){
                output=s.substr(left+1,right-left-1);
                maxcount=count;
            }
        }
        return output;
    }
};