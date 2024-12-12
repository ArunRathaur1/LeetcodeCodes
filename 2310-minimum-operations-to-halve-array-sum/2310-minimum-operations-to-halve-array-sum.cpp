class Solution {
public:
    int halveArray(vector<int>& nums) {
      priority_queue<double,vector<double>>q;
      long double total=std::accumulate(nums.begin(),nums.end(),0.0L);
      long double currsum=total;
      for(auto i: nums)q.push(i);
      int count=0;
      while(currsum>total/2){
        double p=q.top();
        q.pop();
        currsum=currsum-p/2;
        q.push(p/2);
        count++;
      }
        return count;
    }
};