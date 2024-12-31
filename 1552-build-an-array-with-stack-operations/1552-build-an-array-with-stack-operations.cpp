class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
       int index=0;
       int p=target.size();
       vector<string>ans;
       for(int i=1;i<=n;i++){
            if(index<p){
                if(target[index]==i){
                    ans.push_back("Push");
                    index++;
                }
                else{
                    ans.push_back("Push");
                    ans.push_back("Pop");
                }
            }
            else{
                break;
            }
       }
       return ans; 
    }
};