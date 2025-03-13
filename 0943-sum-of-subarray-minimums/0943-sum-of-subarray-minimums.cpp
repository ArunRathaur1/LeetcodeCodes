class Solution {
public:
    int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int l=arr.size();
        stack<pair<int,int>>st;
        vector<long long>result(l,0);
        int ans=0;
        for(int i=0;i<l;i++){
            while(!st.empty()&& st.top().first>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                int index=st.top().second;
                result[i]=(result[index]+arr[i]*(i-index))%mod;
                ans=(ans+result[i])%mod;
            }
            else{
                result[i]=(arr[i]*(i+1))%mod;
                ans=(ans+result[i])%mod;
            }
            st.push({arr[i],i});
        }
        return ans;
    }
};