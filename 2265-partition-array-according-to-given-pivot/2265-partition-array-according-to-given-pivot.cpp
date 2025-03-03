class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
     vector<int>small;
     vector<int>big;
     int count=0;
     for(auto i: nums){
        if(i==pivot)count++;
        else if(i>pivot)big.push_back(i);
        else small.push_back(i);
     }   
        int index=0;
        for(auto i: small){
            nums[index]=i;
            index++;
        }
        for(int i=0;i<count;i++){
            nums[index]=pivot;
            index++;
        }
        for(auto i: big){
            nums[index]=i;
            index++;
        }
        return nums;
    }
};