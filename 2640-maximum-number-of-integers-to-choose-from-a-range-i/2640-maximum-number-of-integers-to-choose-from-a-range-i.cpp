class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>st;
        int s=banned.size();
        for(auto i: banned){
            st.insert(i);
        }
        int count=0;
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end()){
                maxSum-=i;
                if(maxSum<0)break;
                else count++;
            }
        }
        return count;
    }
};