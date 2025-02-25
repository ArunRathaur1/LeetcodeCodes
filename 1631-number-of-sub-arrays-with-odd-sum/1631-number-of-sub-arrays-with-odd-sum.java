class Solution {
    public int numOfSubarrays(int[] arr) {
        double q=1e9+7;
        int currsum=0;
        int evencount=1;
        int oddcount=0;
        int ans=0;
        int p=arr.length;
        for(int i=0;i<p;i++){
            currsum=currsum+arr[i];
            if(currsum%2==0){
                ans=(int)((ans+oddcount)%q);
                evencount++;
            }
            else{
                ans=(int)((ans+evencount)%q);
                oddcount++;
            }
        }
        return ans;
    }
}