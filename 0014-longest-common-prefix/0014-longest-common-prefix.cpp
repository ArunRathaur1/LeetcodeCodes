class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        int n=strs.size();
        for(int i=1;i<n;i++){
            int index=0;
            int flag=1;
            for(auto j:ans){
                if(strs[i][index]!=j||strs[i].length()==index){
                    flag=0;
                    break;  
                }
                index++;
            }
            if(flag==0){
                ans=ans.substr(0,index);
            }
            if(ans=="")return "";
        }
        return ans;
    }
};