class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        int size=folder.size();
        vector<string>ans;
        ans.push_back(folder[0]);
        for(int i=1;i<size;i++){
            string tem=ans.back()+'/';
            int length=tem.length();
            string p=folder[i].substr(0,tem.length());
            if(tem!=p){
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};