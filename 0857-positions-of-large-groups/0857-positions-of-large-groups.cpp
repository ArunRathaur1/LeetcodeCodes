class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        s=s+'1';
      int length=s.length();
      vector<vector<int>>ans;
      int start=0,index=0;
      char ch=s[0];
      for(int i=0;i<length;i++){
            if(ch==s[i]){
                index++;
            }
            else{
                if(index>=3){
                    ans.push_back({start,i-1});
                }
                index=1;
                ch=s[i];
                start=i;
            }
        }  
        return ans;
    }
};