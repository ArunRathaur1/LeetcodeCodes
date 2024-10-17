class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>m;
        int size=nums.size();
        for(int i=0;i<size;i++){
            m[nums[i]]++;
        }
        int k=0;
        for(auto i:m){
            if(i.second==1)
            nums[k]=i.first;
            else if(i.second>=2)
            {
                nums[k]=i.first;
                k++;
                nums[k]=i.first;
            }
            k++;
        }
        return k;
    }
};