class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int>m;
        int l=nums.size();
        int flag=-1;
        for(int i=l-1;i>=0;i--){
            m[nums[i]]++;
            if(m[nums[i]]==2){
                flag=i;
                break;
            }
        }
        if(flag==-1)return 0;
        if((flag+1)%3==0)return (flag+1)/3;
        else return (flag+1)/3+1;
    }
};