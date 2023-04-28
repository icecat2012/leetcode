/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> data;
    int now;
    void flat(vector<NestedInteger> &nestedList)
    {
        for(auto &p:nestedList)
            if(p.isInteger())
                data.push_back(p.getInteger());
            else
                flat(p.getList());
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        now=0;
        flat(nestedList);
    }
    
    int next() {
        return data[now++];
    }
    
    bool hasNext() {
        return now<data.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */