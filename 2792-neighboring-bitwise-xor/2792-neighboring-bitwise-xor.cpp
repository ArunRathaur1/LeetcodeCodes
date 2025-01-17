class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int size=derived.size();
       vector<int>ans(size);
       ans[0]=0;
       for(int i=0;i<size-1;i++){
            if(derived[i]==1){
                if(ans[i]==0)
                    ans[i+1]=1;
                else
                    ans[i+1]=0;
            }
            else{
                ans[i+1]=ans[i];
            }
       }
       if(ans[size-1]^ans[0]==derived[size-1]){
        return true;
       }
       return false;
    }
};