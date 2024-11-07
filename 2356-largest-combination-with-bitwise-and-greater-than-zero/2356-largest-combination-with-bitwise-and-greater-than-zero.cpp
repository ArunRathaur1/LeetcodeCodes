class Solution {
public:
    int largestCombination(vector<int>& ar) {
        int size=ar.size();
        unordered_map<int,unordered_set<int>>m;
        for(int i=0;i<size;i++){
            int x=ar[i];
            int count=1;
            while(x!=0){
                int p=x&1;
                if(p==1){
                     m[i].insert(count);
                }
                count++;
                x=x>>1;
            }
        }
        int maxcount=INT_MIN;
        for(int i=1;i<25;i++){
            int count=0;
            for(int j=0;j<size;j++){
                if(m[j].find(i)!=m[j].end()){
                    count++;
                }
            }
            maxcount=max(count,maxcount);
        }
        return maxcount;
    }
};