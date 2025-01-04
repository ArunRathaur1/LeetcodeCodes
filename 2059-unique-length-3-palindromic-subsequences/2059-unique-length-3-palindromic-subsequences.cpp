class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int count=0;
        int n=s.length();
        for(int i=0;i<26;i++){
            vector<bool>visited(n,false);
            char ch=i+'a';
            int start=0;
            while(start<n&&s[start]!=ch)start++;
            int end=n-1;
            while(end>=0&&s[end]!=ch)end--;
            for(int j=start+1;j<end;j++){
                if(visited[s[j]-'a']==false){
                    visited[s[j]-'a']=true;
                    count++;
                }
            }
        }
        return count;
    }
};