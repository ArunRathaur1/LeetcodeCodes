class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxcount=0;
        for(auto i:s){
            if(i=='('){
                count++;
            }
            else if(i==')'){
                count--;
            }
            maxcount=max(maxcount,count);
        }
        return maxcount;
    }
};