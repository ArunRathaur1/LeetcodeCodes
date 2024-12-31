class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currgas=0;
        int currstation=0;
        int p=gas.size();
        for(int i=0;i<p;i++){
            if(currgas+gas[i]-cost[i]<0){
                currgas=0;
                if(i+1<p){
                    currstation=i+1;
                }
            }
            else{
                currgas=currgas+gas[i]-cost[i];
            }
        }
        cout<<currstation<<endl;
        cout<<currgas<<endl;
        for(int i=0;i<=currstation;i++){
            currgas=currgas+gas[i]-cost[i];
            if(currgas<0){ 
                break;
            }
        }
        cout<<currgas<<endl;
        if(currgas<0){
            return -1;
        }
        else{
            return currstation;
        }
    }
};