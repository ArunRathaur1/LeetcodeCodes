class LRUCache {
public:
    map<int,list<pair<int,int>>::iterator>m;
    list<pair<int,int>>lr;
    int size;
    int count=0;
    LRUCache(int capacity) {
       size=capacity;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            auto it=m[key];
            int x=it->second;
            lr.splice(lr.begin(),lr,it);
            return x;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            m[key]->second=value;
            lr.splice(lr.begin(),lr,m[key]);
        }
        else if(count<size){
            pair<int,int>p={key,value};
            lr.push_front(p);
            m[key]=lr.begin();
            count++;
        }
        else{
            pair<int,int>p=lr.back();
            lr.pop_back();
            pair<int,int>n={key,value};
            m.erase(p.first);
            lr.push_front(n);
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