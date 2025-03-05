class Solution {
public:
    long long coloredCells(int n) {
        long long x=1;
        for(int i=1;i<n;i++){
            x=x+4*i;
        }
        return x;
    }
};