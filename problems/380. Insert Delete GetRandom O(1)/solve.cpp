class RandomizedSet {
public:
    unordered_set<int> data;

    RandomizedSet() {
        srand( time(NULL) );
    }
    
    bool insert(int val) {
        auto p = data.insert(val);
        return p.second;
    }
    
    bool remove(int val) {
        auto p = data.erase(val);
        return p;
    }
    
    int getRandom() {
        int a=rand();
        auto it=data.begin();
        for(int i=0;i<a%data.size();++i)
            ++it;
        return *(it);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */