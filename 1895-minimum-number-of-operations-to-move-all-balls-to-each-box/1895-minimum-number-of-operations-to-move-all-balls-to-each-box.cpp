class Solution {
public:
    vector<int> minOperations(string boxes) {
        int k=boxes.length();
        vector<int>ans;
        vector<int>ar;
        for(int i=0;i<k;i++){
            if(boxes[i]=='1'){
                ar.push_back(i);
            }
        }
        for(int i=0;i<ar.size();i++){
            cout<<ar[i]<<" ";
        }
        cout<<endl;
        int q=ar.size();
        for(int i=0;i<k;i++){
            int sum=0;
            for(int j=0;j<q;j++){
                sum=sum+abs(ar[j]-i);
            }
            ans.push_back(sum);
        }
        return ans;
    }
};