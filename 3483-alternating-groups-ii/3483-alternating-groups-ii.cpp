class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int count=1;
        int ans=0;
        int right=1;
        colors.insert(colors.end(),colors.begin(),colors.begin()+k-1);
        int n=colors.size();
        while(right<n){
            if(colors[right-1]!=colors[right]){
                right++;
                count++;
                if(count==k){
                    ans++;
                    count--;
                }
            }
            else{
                count=1;
                right++;
            }
        }
        return ans;
    }
};