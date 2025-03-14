class StockSpanner {
public:
    stack<pair<int,int>>st;
    int count=0;    
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty()){
            st.push({price,1});
        }
        else if(st.top().first>price){
            st.push({price,1});
        }
        else{
            int count=0;
            while(!st.empty()&& st.top().first<=price){
                count+=st.top().second;
                st.pop();
            }
            st.push({price,count+1});
        }
        return st.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */