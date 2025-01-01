class Solution {
public:
    bool maxscore(vector<int>&nums,int left,int right,int p1,int p2,int turn){
        if(left>right)return p1>=p2;
        bool p=false;
        if(turn%2==0){
           p= maxscore(nums,left+1,right,p1+nums[left],p2,1)||
           maxscore(nums,left,right-1,p1+nums[right],p2,1);
        }
        else{
            p= (maxscore(nums,left+1,right,p1,p2+nums[left],0)&&
           maxscore(nums,left,right-1,p1,p2+nums[right],0));
        }
        return p;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
       return maxscore(nums,0,nums.size()-1,0,0,0);
    }
};