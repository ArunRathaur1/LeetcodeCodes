class RandomizedSet {
public:
    unordered_map<int,int>ar;
    vector<int>values;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(ar.find(val)==ar.end()){
            values.push_back(val);
            ar[val]=values.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(ar.find(val)!=ar.end()){
            int index=ar[val];
            ar[values[values.size()-1]]=index;
            swap(values[values.size()-1],values[ar[val]]);
            values.pop_back();
            ar.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int r=rand()%values.size();
        return values[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */