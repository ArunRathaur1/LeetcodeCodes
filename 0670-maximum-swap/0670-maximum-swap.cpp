class Solution {
public:
    int maximumSwap(int num) {
        string number=to_string(num);
        int length=number.length();
        for(int i=0;i<length;i++){
            int k=number[i]-'0';
            int p=INT_MIN;
            int index=i;
            for(int j=length-1;j>i;j--){
                if(p<number[j]-'0'){
                    p=number[j]-'0';
                    index=j;
                }
            }
            if(k<p){
               swap(number[i],number[index]);
               return stoi(number); 
            }
        }
        return num;
    }
};