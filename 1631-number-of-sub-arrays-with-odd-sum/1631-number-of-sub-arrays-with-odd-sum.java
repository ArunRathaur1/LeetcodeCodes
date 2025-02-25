class Solution {
    public int numOfSubarrays(int[] arr) {
        int q=1000000007;
        int currsum=0;
        int evencount=1;
        int oddcount=0;
        int ans=0;
        int p=arr.length;
        for(int i=0;i<p;i++){
            currsum=currsum+arr[i];
            if(currsum%2==0){
                ans=((ans+oddcount)%q);
                evencount++;
            }
            else{
                ans=((ans+evencount)%q);
                oddcount++;
            }
        }
        return ans;
    }
}