class Solution {
    int mod=1e9 + 7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        map<int,vector<pair<int,int>>>m;
        set<int>st;
        for(auto i: arr)st.insert(i);
        map<int,int>ans;
        for(int i=0;i<n;i++){
            int k=arr[i];
            for(int j=0;j<n;j++){
                if(j!=i&&k%arr[j]==0){
                    if(st.find(arr[j])!=st.end()&& st.find(k/arr[j])!=st.end())
                        m[k].push_back({arr[j],k/arr[j]});
                }
            }
            if(m[k].size()==0){
                m[k].push_back({-1,-1});
            }
        }
        for(auto value:m){
            long tem=0;
            for(auto pair:value.second){
                long long k1=1,k2=1;
                if(pair.first==-1)break;
                if(ans.find(pair.first)!=ans.end()){ 
                    k1=ans[pair.first];
                }
                if(ans.find(pair.second)!=ans.end()){
                    k2=ans[pair.second];
                }
                tem=(tem+k1*k2)%mod;
            }
            ans[value.first]=tem+1;
        }
        int output=0;
        for(auto i:ans){
            output=(output+i.second)%mod;
        }
        return output;
    }
};