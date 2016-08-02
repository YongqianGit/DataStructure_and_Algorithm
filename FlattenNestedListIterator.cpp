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
private:
    stack<NestedInteger> sk;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int sz = nestedList.size();
        for (int i = sz - 1; i >= 0; i--) {
            sk.push(nestedList[i]);
        }
    }
 
    int next() {
        int n = sk.top().getInteger();
        sk.pop();
        return n;
    }

    bool hasNext() {
        while (!sk.empty() ) {
            NestedInteger cur = sk.top();
            if ( cur.isInteger() ) {return true;}
            else {sk.pop(); }
            
            int sz_cur = cur.getList().size();
            for (int i = sz_cur - 1; i >= 0; i--) {
                sk.push(cur.getList()[i]);
            }
        }
        
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
