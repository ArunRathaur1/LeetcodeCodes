class Solution {
public:
    vector<bool> checkIfPrerequisite(int course, vector<vector<int>>& req, vector<vector<int>>& queries) {
       vector<vector<int>>distance(course,vector<int>(course,INT_MAX));
       for(auto i: req){
            distance[i[0]][i[1]]=1;
       } 
       for(int i=0;i<course;i++){
        for(int j=0;j<course;j++){
            for(int k=0;k<course;k++){
                if(distance[j][i]!=INT_MAX&& distance[i][k]!=INT_MAX){
                    distance[j][k]=min(distance[j][k],distance[j][i]+distance[i][k]);
                }
            }
        }
       }
        vector<bool>ans;
        for(auto i:queries){
            int first=i[0];
            int second=i[1];
            if(distance[first][second]!=INT_MAX){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};