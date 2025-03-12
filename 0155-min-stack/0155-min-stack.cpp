class MinStack {
public:
    stack<long long>st;
    long long minvalue=INT_MAX;
    MinStack() {
        
    }
    
    void push(long long val) {
        if(st.empty()){
            st.push(val);
            minvalue=val;
        }
        else if(val>=minvalue){
            st.push(val);
        }
        else{
            long long k=2*val-minvalue;
            minvalue=val;
            st.push(k);
        }
    }
    
    void pop() {
        if(st.empty())return;
        if(st.top()<minvalue){
            long long k=st.top();
            st.pop();
            minvalue=2*minvalue-k;
        }
        else{
            st.pop();
        }
    }
    
    int top() {
        if(st.empty())return -1;
        if(st.top()<minvalue)return minvalue;
        else return st.top();
    }
    
    int getMin() {
        return minvalue;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * long long param_3 = obj->top();
 * long long param_4 = obj->getMin();
 */