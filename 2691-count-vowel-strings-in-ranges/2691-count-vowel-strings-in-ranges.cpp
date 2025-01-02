class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
      int n=words.size();
      int p=queries.size();
      vector<int>count(n+1,0);
      vector<char>ch={'a','e','i','o','u'};
      for(int i=0;i<n;i++){
        int m=words[i].length();
        int flag=0;
            for(int j=0;j<5;j++){
              for(int k=0;k<5;k++){
                if(words[i][0]==ch[j]&&words[i][m-1]==ch[k]){
                    flag=1;
                }
              } 
            }
            if(flag==1){
                count[i+1]=count[i]+1;
            }
            else{
                count[i+1]=count[i];
            }
        } 
        vector<int>ans;
        for(int i=0;i<p;i++){
            ans.push_back(count[queries[i][1]+1]-count[queries[i][0]]);
        }
        return ans;
    }
};