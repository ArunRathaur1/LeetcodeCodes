class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>ar(n,0);
        for(int i=0;i<edges.size();i++){
           ar[edges[i][1]]=-1;
        }
        int count=0;
        int index=-1;
        for(int i=0;i<n;i++){
            if(ar[i]==0){
                index=i;
                count++;
            }
        }
        if(count>1){
            return -1;
        }
        return index;

    }
};