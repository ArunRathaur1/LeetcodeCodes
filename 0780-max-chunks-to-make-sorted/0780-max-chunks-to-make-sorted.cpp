class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        int c=0;
        while(i<n){
            if(arr[i]==i){
                c++;
                i++;
            }
            else{
                int tem=arr[i];
                while(i<=tem){
                    if(arr[i]>tem){
                        tem=arr[i];
                    }
                    i++;
                }
                c++;
            }
        }
        cout<<c<<endl;
        return c;
    }
};