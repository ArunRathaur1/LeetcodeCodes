class NumberContainers {
public:
    unordered_map<int,int>m1;
    unordered_map<int,set<int>>m2;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(m1.find(index)!=m1.end()){
            m2[m1[index]].erase(index);
            if(m2[m1[index]].size()==0)m2.erase(m1[index]);
        }
        m1[index]=number;
        m2[number].insert(index);
    }
    
    int find(int number) {
        if(m2.find(number)!=m2.end()){
            return *m2[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */