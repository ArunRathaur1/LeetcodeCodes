class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>ar;
        for(int i=0;i<strs.size();i++){
            vector<int>tem(26,0);
            for(int j=0;j<strs[i].length();j++){
                tem[strs[i][j]-'a']++;
            }
            ar[tem].push_back(strs[i]);
        }
       vector< vector<string>>ans;
        for(auto i:ar){
            ans.push_back(i.second);
        }
        return ans;
    }
};