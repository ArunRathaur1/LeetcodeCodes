class Solution {
public:
    vector<int> nextsmaller(vector<int>&ar){
        stack<pair<int,int>>st;
        int l=ar.size();
        vector<int>result(l,l);
        for(int i=l-1;i>=0;i--){
            while(!st.empty()&& st.top().first>=ar[i]){
                st.pop();
            }
            if(!st.empty()){
                result[i]=st.top().second;
            }
            st.push({ar[i],i});
        }
        return result;
    }
    vector<int> previousSmaller(vector<int>&ar){
        stack<pair<int,int>>st;
        int l=ar.size();
        vector<int>result(l,-1);
        for(int i=0;i<l;i++){
            while(!st.empty()&& st.top().first>=ar[i]){
                st.pop();
            }
            if(!st.empty()){
                result[i]=st.top().second;
            }
            st.push({ar[i],i});
        }
        return result;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>next=nextsmaller(heights);
        vector<int>previous=previousSmaller(heights);
        int l=heights.size();
        int ans=0;
        for(int i=0;i<l;i++){
            int width=next[i]-previous[i]-1;
            ans=max(ans,width*heights[i]);
        }
        return ans;
    }
};