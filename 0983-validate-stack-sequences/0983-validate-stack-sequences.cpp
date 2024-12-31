class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int tem=0;
        int x=popped.size();
        for(auto i: pushed){
            st.push(i);
            while(!st.empty()&& tem<x&& st.top()==popped[tem]){
                st.pop();
                tem++;
            }
        }
        if(st.empty())return true;
        return false;
    }
};