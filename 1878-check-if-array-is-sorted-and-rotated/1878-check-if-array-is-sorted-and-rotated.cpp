class Solution {
public:
    bool check(vector<int>& ar) {
       int flag=0;
       int l=ar.size();
       for(int i=0;i<l-1;i++){
            if(flag==1&& ar[i]>ar[i+1])return false;
            else if(ar[i]>ar[i+1]){
                flag=1;
            }
       } 
       if(flag==0&& ar[0]<=ar[l-1])return true;
       if(flag==1&& ar[0]>=ar[l-1])return true;
       return false;
    }
};