class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
       priority_queue<int>q;
       for(int i=0;i<nums.size();i++)
       q.push(nums[i]);
       int index=0;
       long long score=0;
       while(index<k){
        int p=q.top();
        score=score+p;
        q.pop();
        if(p%3==0){
            q.push(p/3);
        }
        else{
            q.push(p/3+1);
        }
        index++;
       } 
       return score;
    }
};