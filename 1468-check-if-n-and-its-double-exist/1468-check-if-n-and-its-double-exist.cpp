class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]=i;
        }
        int flag=0;
        for(int i=0;i<arr.size();i++){
            if(m.find(arr[i]*2)!=m.end()&& m[arr[i]*2]!=i){
                flag=1;
                break;
            }
            if(arr[i]%2==0&& m.find(arr[i]/2)!=m.end() && m[arr[i]*2]!=i){
                flag=1;
                break;
            }
        }
        if(flag==1)return true;
        return false;
    }
};