class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int currmax=INT_MIN;
        int maxscore=INT_MIN;
        int n=values.size();
        for(int i=1;i<n;i++){
            currmax=max(values[i-1],currmax)-1;
            maxscore=max(maxscore,currmax+values[i]);
        }
        return maxscore;
    }
};