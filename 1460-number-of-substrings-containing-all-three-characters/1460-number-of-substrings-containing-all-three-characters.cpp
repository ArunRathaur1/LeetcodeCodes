class Solution {
public:
    int numberOfSubstrings(string s) {
        // unordered_map<char,int>m;
        // int l=s.length();
        // int ans=0;
        // int left=0;
        // int right=0;
        // while(right<l){
        //     m[s[right]]++;
        //     while(m.size()==3){
        //         ans=ans+(l-right);
        //         m[s[left]]--;
        //         if(m[s[left]]==0)m.erase(s[left]);
        //         left++;
        //         continue;
        //     }
        //     right++;
        // }
        // return ans;
        int a=-1;
        int b=-1;
        int c=-1;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a')a=i;
            else if(s[i]=='b')b=i;
            else c=i;
            if(a!=-1&& b!=-1&&c!=-1){
                ans=ans+min({a,b,c})+1;
            }
        }
        return ans;
    }
};