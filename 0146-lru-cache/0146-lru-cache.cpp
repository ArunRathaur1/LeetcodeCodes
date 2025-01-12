class LRUCache {
public:
    unordered_map<int,list<pair<int,int>>::iterator>m;
    list<pair<int,int>>lr;
    int capacity=0;
    int x=0;
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    int get(int key) {
        if(m.find(key)!=m.end()){
            auto it=m[key];
            lr.splice(lr.begin(),lr,it);
            return m[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            auto it =m[key];
            it->second=value;
            lr.splice(lr.begin(),lr,it);
        }
        else{
            if(lr.size()==capacity){
                int temnode=lr.back().first;
                m.erase(temnode);
                lr.pop_back();
            }
            lr.emplace_front(key,value);
            m[key]=lr.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */