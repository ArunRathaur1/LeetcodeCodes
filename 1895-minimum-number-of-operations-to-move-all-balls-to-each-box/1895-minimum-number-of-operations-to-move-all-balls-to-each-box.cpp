class Solution {
public:
    vector<int> minOperations(string boxes) {
       int sum=0;
       int left=0;
       int right=0;
       int size=boxes.length();
       for(int i=0;i<size;i++){
        if(boxes[i]=='1'){
            sum=sum+i;
            right++;
            }
       }
       vector<int>ans(size,0);
       ans[0]=sum;
       if(boxes[0]=='1'){
        right--;
        left++;
       }
        for(int i=1;i<size;i++){
            ans[i]=ans[i-1]-right+left;
            if(boxes[i]=='1'){
                left++;
                right--;
            }
        }
        return ans;
    }
};