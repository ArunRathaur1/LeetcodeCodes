class Solution {
public:
    int countallcombination(vector<int>&nums,int value,int currvalue,int index,int n){
        if(index==n and currvalue==value)return 1;
        if(index>=n)return 0;
        int p=currvalue|nums[index];
        int include=countallcombination(nums,value,p,index+1,n);
        int exclude=countallcombination(nums,value,currvalue,index+1,n);
        return include+exclude;
    }
    int countMaxOrSubsets(vector<int>& nums) {
     int maxvalue=0;
     int n=nums.size();
     for(int i=0;i<n;i++){
        maxvalue=maxvalue|nums[i];
     }  
     return countallcombination(nums,maxvalue,0,0,n); 
    }
};