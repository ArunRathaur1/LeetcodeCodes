class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int n=nums.size();
        for(auto i: nums)st.insert(i);
        int currlength=0;
        for(auto number: st){
            if(st.find(number-1)==st.end()){
                int temlength=1;
                int k=number;
                while(st.find(k+1)!=st.end()){
                    k++;
                    temlength++;
                }
                currlength=max(currlength,temlength);
            }
        }
        return currlength;
    }
};