class Solution {
public:
vector<int>countsort(vector<int>ar,int index){
    vector<int>array(10,0);
    int x=ar.size();
    vector<int>output(x,0);
    for(int i=0;i<x;i++){
        int p=(ar[i]/index)%10;
        array[p]++;
    }
    for(int i=1;i<10;i++){
        array[i]=array[i]+array[i-1];
    }
    for(int i=x-1;i>=0;i--){
        int p=(ar[i]/index)%10;
        output[array[p]-1]=ar[i];
        array[p]--;
    }
    return output;

}
void radixsort(vector<int>&ar,int n){
    int m=*max_element(ar.begin(),ar.end());
    int digits=to_string(m).length();
    long long index=1;
    for(int i=0;i<digits;i++){
       vector<int>csort=countsort(ar,index);
       ar=csort;
       index=index*10;
    }
}
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
       if(n<2)return false;
       radixsort(nums,n);
       int m=INT_MIN;
       for(int i=1;i<n;i++){
            m=max(m,nums[i]-nums[i-1]);
       }
       return m;
    }
};