class LRUCache {
public:
    LRUCache(int capacity) {
        size=capacity;
    }
    int size;
    list<pair<int, int>> data;
    unordered_map<int, list<pair<int, int>>::iterator> index;
    int get(int key) 
    {
        if (!index.count(key))
            return -1;
        data.splice(data.begin(), data, index[key]);
        return index[key]->second;
    }
    
    void put(int key, int value) {
        if (index.count(key))
        {
            data.splice(data.begin(), data, index[key]);
            data.begin()->second = value;
            return;
        }
        if (data.size()==size)
        {
            index.erase(data.back().first);
            data.pop_back();
        }
        data.push_front(make_pair(key, value));
        index[key] = data.begin();
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */