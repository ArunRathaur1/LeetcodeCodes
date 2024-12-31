class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      int p1=0;
      int p2=0;
      int l1=pushed.size();
      int l2=popped.size();
      stack<int>st;
      while(p1!=l1&&p2!=l2){
        while(p1<l1&&popped[p2]!=pushed[p1]){
            st.push(pushed[p1]);
            p1++;
        }
        p2++;
        while(p2<l2 &&!st.empty()&& st.top()==popped[p2]){
            st.pop();
            p2++;
        }
        p1++;
      }
      if(st.empty()){
        return true;
      }
      return false;

    }
};