class Solution {
public:
    long long minimumSteps(string s) {
        long long count=0;
        int n=s.length();
        long long steps=0;
        for(char c:s){
            if(c=='1'){
                steps++;
            }
            else{
                count=count+steps;
            }
        }
       return count;
    }
};