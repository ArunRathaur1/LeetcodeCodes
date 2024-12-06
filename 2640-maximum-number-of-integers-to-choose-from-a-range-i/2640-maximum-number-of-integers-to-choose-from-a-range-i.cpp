class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int index=0;
        sort(banned.begin(),banned.end());
        int count=0;
        for(int i=1;i<=n;i++){
            if(index<banned.size()&& banned[index]==i){
               while(index<banned.size()&& banned[index]==i)
                index++;
            }
            else{
                maxSum-=i;
                if(maxSum<0)break;
                count++;
            }
        }
        return count;
    }
};