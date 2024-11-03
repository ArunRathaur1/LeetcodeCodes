class Solution {
public:
    int bestClosingTime(string customers) {
      int preNcount=0;
      int postYcount=0;
      int size=customers.size();
      for(int i=0;i<size;i++){
        if(customers[i]=='Y')postYcount++;
      }
      int value=postYcount+preNcount;
      int index=-1;
        for(int i=0;i<size;i++){
            if(customers[i]=='Y'){
                postYcount--;
            }
            else if(customers[i]=='N'){
                preNcount++;
            }
            int tem=postYcount+preNcount;
            if(value>tem){
                value=tem;
                index=i;
            }
        }
        return index+1;
    }
};