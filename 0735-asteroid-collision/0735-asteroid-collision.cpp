class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ar) {
        int l = ar.size();
        stack<int> st;
        for (int i = 0; i < l; i++) {
            while (!st.empty() && st.top() > 0 && ar[i] < 0) {
                int k = st.top();
                if (abs(k) >abs( ar[i])) {
                    ar[i] = 0;
                    break;
                } else if (abs(k) < abs(ar[i])) {
                    st.pop();
                } else {
                    st.pop();
                    ar[i] = 0;
                    break;
                }
            }
            if (abs(ar[i]) > 0) {
                st.push(ar[i]);
            }
        }
        vector<int>ans(st.size());
        int index=st.size()-1;
        while(!st.empty()){
            ans[index]=st.top();
            st.pop();
            index--;
        }
        return ans;
    }
};