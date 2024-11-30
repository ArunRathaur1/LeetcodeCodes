class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n=grades.size();
        int count=0,k=2;
        for(int i=0;i<n;i+=k++)
        {
           count++;
        }
        return count;
    }
};