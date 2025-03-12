class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int k=*max_element(nums2.begin(),nums2.end())+1;
        vector<int>nextGreater(k,0);
        int l=nums2.size();
        stack<int>st;
        for(int i=l-1;i>=0;i--){
            if(st.empty()){
                st.push(nums2[i]);
                nextGreater[nums2[i]]=-1;
            }
            else{
                while(!st.empty()&&st.top()<nums2[i]){
                    st.pop();
                }
                if(st.empty()){
                    nextGreater[nums2[i]]=-1;
                }
                else{
                    nextGreater[nums2[i]]=st.top();
                }
                st.push(nums2[i]);
            }
        }
        vector<int>ans;
        for(auto i: nums1){
            ans.push_back(nextGreater[i]);
        }
        return ans;
    }
};