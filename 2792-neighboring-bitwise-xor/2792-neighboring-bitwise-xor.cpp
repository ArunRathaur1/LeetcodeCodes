class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int size=derived.size();
        int ans=0;
       for(int i=0;i<size-1;i++){
            if(derived[i]==1){
                if(ans==0)
                    ans=1;
                else
                    ans=0;
            }
       }
       if(ans^0==derived[size-1]){
        return true;
       }
       return false;
    }
};